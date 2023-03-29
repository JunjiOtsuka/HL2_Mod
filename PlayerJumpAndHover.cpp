/******************LOCAL VARIABLE*****************/
	int buttonsChanged = (mv->m_nOldButtons ^ mv->m_nButtons);	    // These buttons have changed this frame
	int buttonsPressed = buttonsChanged & mv->m_nButtons;			// The changed ones still down are "pressed"

	trace_t tr; // Create our trace_t class to hold the end result
	// Do the TraceLine, and write our results to our trace_t class, tr.
	Vector point;
	float flOffset = 50.0f;
	point[0] = mv->GetAbsOrigin()[0];
	point[1] = mv->GetAbsOrigin()[1];
	point[2] = mv->GetAbsOrigin()[2] - flOffset;
	Vector bumpOrigin;
	bumpOrigin = mv->GetAbsOrigin();
	TryTouchGround(bumpOrigin, point, GetPlayerMins(), GetPlayerMaxs(), MASK_PLAYERSOLID, COLLISION_GROUP_PLAYER_MOVEMENT, tr);

/*******************FUNCTION*********************/
// not fully underwater condition
// added before 
// Set final flags.  CategorizePosition();
CGameMovement::FullWalkMove( )
if (player->GetGroundEntity() == NULL)
{
	//if jump height is above threshold
	if (!tr.m_pEnt)
	{
		Msg("%s \n", "above threshold");
		if (buttonsPressed & IN_JUMP && DoubleJumpCounter > 0)
		{
			mv->m_vecVelocity[2] = 200;

			Msg("%s \n", "double jump");
			Msg("%i \n", DoubleJumpCounter);
			DoubleJumpCounter--;
		}
		
		//hover here
		else if (mv->m_nButtons & IN_JUMP && DoubleJumpCounter == 0 && mv->m_vecVelocity[2] < 0)
		{
			mv->m_vecVelocity[2] = 0;
			Msg("%s \n", "hovering"); 
		}
	}
}