#include "cPlayerCharacter.h"

const sf::Vector2f cPlayerCharacter::PLAYER_SIZE = sf::Vector2f(24, 32);
const sf::Vector2f cPlayerCharacter::PLAYER_COLLIDER_OFFSET = sf::Vector2f(0, -16);
const sf::FloatRect cPlayerCharacter::PLAYER_BOUNDS = sf::FloatRect(PLAYER_COLLIDER_OFFSET, PLAYER_SIZE);
const sf::Vector2f cPlayerCharacter::PLAYER_MAX_VELOCITY = sf::Vector2f(350, 700);

cPlayerCharacter::cPlayerCharacter(sf::Vector2f _position, cPlayerInput& playerInput)
    : cCharacter(eCharacterType::TYPE_PLAYER, _position, PLAYER_BOUNDS, PLAYER_COLLIDER_OFFSET, PLAYER_MAX_VELOCITY)
    , mPlayerInput(playerInput)
    , m_vPlayerInputNormalized(sf::Vector2f(0, 0))
{
    mVelocity = sf::Vector2f(0.0f, 0.0f);
    mMaxVelocity = sf::Vector2f(300, 600);
    mWallslideJumpImpulse = sf::Vector2f(150, 60);
    mDebugColliderShape.setPosition(mPosition);
    mDebugColliderShape.setOutlineColor(sf::Color::Red);
    mDebugColliderShape.setOutlineThickness(2);
    mDebugColliderShape.setFillColor(sf::Color::Transparent);
}

cPlayerCharacter::~cPlayerCharacter()
{
}

void cPlayerCharacter::Update(float DeltaSeconds)
{
    HandleInput();

    // No Input
    if (mIsGrounded && m_vPlayerInputNormalized.x == 0) {   
        mPlayerAnimator.SetSliding(true);
        // Velocity deadzone
        if (std::abs(mVelocity.x) < mVelocityDeadzone) {
            // Zero player velocity here
            mVelocity.x = 0.0f;
            mPlayerAnimator.SetSliding(false);
            mPlayerAnimator.SetRunning(false);
        }
        else {
            // slow player horizontal speed
            if (mIsGrounded)
            {
                mVelocity.x *= 1 - mVelocityDampGrounded * DeltaSeconds;
                
            }
            else
            {
                mVelocity.x *= 1 - mVelocityDampAirborne * DeltaSeconds;
            }
        }
    }
    else
    {   // Input detected, add horizontal speed to player
        mPlayerAnimator.SetSliding(false);
        if (mIsGrounded)
        {
            mVelocity += mMoveInputMultGrounded * m_vPlayerInputNormalized;
            mPlayerAnimator.SetRunning(true);
        }
        else
        {
            mVelocity += mMoveInputMultAirborne * m_vPlayerInputNormalized;
        }
    }

    CharacterPhysicsUpdate(DeltaSeconds);

    // Tell animator jump peak has been reached
    if (mIsGrounded == false && mVelocity.y < -1 && mVelocity.y > -20)
    {
        mPlayerAnimator.JumpPeak();
    }

    // Face Left/Right
    if (mVelocity.x > 1) {
        mPlayerAnimator.FaceRight();
        mIsFacingRight = true;
    }
    else if (mVelocity.x < -1) {
        mPlayerAnimator.FaceLeft();
        mIsFacingRight = false;
    }

    // Update Animation
    mPlayerAnimator.Animate(mPosition, DeltaSeconds);
}

void cPlayerCharacter::Draw(sf::RenderWindow& renderWindow) 
{
    //DrawDebug(renderWindow);
    mPlayerAnimator.Draw(renderWindow);
}

void cPlayerCharacter::Jump()
{
    mIsGrounded = false;
    //mVelocity.y -= mJumpImpulse;
    mVelocity.y -= sqrtf(2.0f * mGravity * mJumpImpulse); // someone said this was good?
}

void cPlayerCharacter::JumpWallsliding()
{
    mIsTouchingWall = false;
    mIsWallsliding = false;
    mVelocity.y = -sqrtf(2.0f * mGravity * mWallslideJumpImpulse.y);
    if (mIsFacingRight) {
        mVelocity.x = -mWallslideJumpImpulse.x;
    }
    else {
        mVelocity.x = mWallslideJumpImpulse.x;
    }
}

void cPlayerCharacter::HandleInput()
{
    // Arrow Keys
    if (mPlayerInput.IsMoveRightInputPressed()) {
        m_vPlayerInputNormalized.x = 1;
    }
    else if (mPlayerInput.IsMoveLeftInputPressed()) {
        m_vPlayerInputNormalized.x = -1;
    }
    else {
        m_vPlayerInputNormalized.x = 0;
    }
    // Space
    if (mPlayerInput.IsJumpInputPressed() && mIsGrounded)
    {
        mPlayerAnimator.BeginJump();
        Jump();
    }
    else if (mPlayerInput.IsJumpInputPressed() && mIsTouchingWall)
    {
        mPlayerAnimator.BeginJump();
        JumpWallsliding();
    }
}


