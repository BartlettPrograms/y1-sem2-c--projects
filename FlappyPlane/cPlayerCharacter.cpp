#include "cPlayerCharacter.h"

cPlayerCharacter::cPlayerCharacter()
    : cPhysicsObject()
    , mBody(sf::Vector2f(24, 24))
    , cBoxCollider(mBody)
    , mMaxVelocity(sf::Vector2f(350, 700))
    , m_vPlayerInputNormalized(sf::Vector2f(0, 0))
{
    // Initial Position
    mPosition = sf::Vector2f(700, 683);
    mVelocity = sf::Vector2f(0.0f, 0.0f);
    mBody.setOrigin(sf::Vector2f(12, 0));
    mBody.setPosition(mPosition);
    mBody.setOutlineColor(sf::Color::Red);
    mBody.setOutlineThickness(7);
    mBody.setFillColor(sf::Color::Transparent);
}

cPlayerCharacter::~cPlayerCharacter()
{
    delete mSprite;
}

void cPlayerCharacter::Update(float DeltaSeconds)
{
    HandleInput();

    // Collider currently follows this objects position
    mBody.setPosition(mPosition);

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
    // Clamp x position between 0 and 1366
    if (mPosition.x < 64)            // og: 0
    {
        mPosition.x = 64;
        mVelocity.x = 0;
    }
    else if (mPosition.x > 1302)    // og: 1366
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
    }
    else if (mVelocity.x < -1) {
        mPlayerAnimator.FaceLeft();
    }

    // Update Animation
    mPlayerAnimator.Animate(mPosition, DeltaSeconds);
}

void cPlayerCharacter::Draw(sf::RenderWindow& renderWindow) 
{
    mPlayerAnimator.Draw(renderWindow);
    renderWindow.draw(mBody);
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