#include "cPlayerCharacter.h"

cPlayerCharacter::cPlayerCharacter()
    : cCharacter(eCharacterType::TYPE_PLAYER, sf::FloatRect(sf::Vector2f(0,0), sf::Vector2f(24, 24)), sf::Vector2f(700, 683), sf::Vector2f(350, 700))
    , m_vPlayerInputNormalized(sf::Vector2f(0, 0))
{
    mVelocity = sf::Vector2f(0.0f, 0.0f);
    mDebugColliderShape.setOrigin(sf::Vector2f(0, -10));
    mDebugColliderShape.setPosition(mPosition);
    mDebugColliderShape.setOutlineColor(sf::Color::Red);
    mDebugColliderShape.setOutlineThickness(2);
    mDebugColliderShape.setFillColor(sf::Color::Transparent);

    mDebugPositionShape.setOrigin(sf::Vector2f(2, 2));
}

cPlayerCharacter::~cPlayerCharacter()
{
    delete mSprite;
}

void cPlayerCharacter::Update(float DeltaSeconds)
{
    HandleInput();

    // Collider currently follows this objects position
    mBounds.position = mPosition;
    mDebugPositionShape.setPosition(mPosition);

    // No Input
    if (m_vPlayerInputNormalized.x == 0) {   
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
            if (m_bGrounded)
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
        if (m_bGrounded)
        {
            mVelocity += mMoveInputMultGrounded * m_vPlayerInputNormalized;
            mPlayerAnimator.SetRunning(true);
        }
        else
        {
            mVelocity += mMoveInputMultAirborne * m_vPlayerInputNormalized;
        }
    }

    // Physics update
    mVelocity.y += mGravity * DeltaSeconds; // gravity
    mPosition += mVelocity * DeltaSeconds; // movement


    // Clamp position to not fall below ground && grounded reset
    if (mPosition.y > 768 - 30)
    {
        mPlayerAnimator.EndFall();
        mPosition.y = 768 - 30;
        mVelocity.y = 0;
        m_bGrounded = true;
    }
    // Clamp x position to keep player inside screen
    if (mPosition.x < 64)
    {
        mPosition.x = 64;
        mVelocity.x = 0;
    }
    else if (mPosition.x > 1302)
    {
        mPosition.x = 1302;
        mVelocity.x = 0;
    }

    // Tell animator jump peak has been reached
    if (m_bGrounded == false && mVelocity.y < -1 && mVelocity.y > -20)
    {
        mPlayerAnimator.JumpPeak();
    }


    // Clamp velocity to max velocity
    if (mVelocity.x > mMaxVelocity.x)           { mVelocity.x = mMaxVelocity.x; }
    if (mVelocity.x < (-1 * mMaxVelocity.x))    { mVelocity.x = (-1 * mMaxVelocity.x); }
    if (mVelocity.y > mMaxVelocity.y)           { mVelocity.y = mMaxVelocity.y; }
    if (mVelocity.y < (-1 * mMaxVelocity.y))    { mVelocity.y = (-1 * mMaxVelocity.y); }

    if (mVelocity.x > 1) {
        mPlayerAnimator.FaceRight();
        //mBounds.setOrigin(sf::Vector2f(-3, 0));
    }
    else if (mVelocity.x < -1) {
        mPlayerAnimator.FaceLeft();
        //mBody.setOrigin(sf::Vector2f(27, 0));
    }

    // Update Animation
    mPlayerAnimator.Animate(mPosition, DeltaSeconds);
}

void cPlayerCharacter::Draw(sf::RenderWindow& renderWindow) 
{
    DrawDebug(renderWindow);
    mPlayerAnimator.Draw(renderWindow);
}

void cPlayerCharacter::Jump()
{
    m_bGrounded = false;
    mVelocity.y -= m_fJumpImpulse;
}

void cPlayerCharacter::HandleInput()
{
    // Arrow Keys
    if (mPlayerInput.IsRightArrowPressed()) {
        m_vPlayerInputNormalized.x = 1;
    }
    else if (mPlayerInput.IsLeftArrowPressed()) {
        m_vPlayerInputNormalized.x = -1;
    }
    else {
        m_vPlayerInputNormalized.x = 0;
    }
    // Space
    if (mPlayerInput.IsSpacePressed() && m_bGrounded)
    {
        mPlayerAnimator.BeginJump();
        Jump();
    }
}

void cPlayerCharacter::DrawDebug(sf::RenderWindow& renderWindow)
{
    mDebugPositionShape.setPosition(mPosition);
    renderWindow.draw(mDebugColliderShape); // draw collider
    renderWindow.draw(mDebugPositionShape); // draw player ground center
}
