CGameMovement::Duck( void )
if (player->GetAbsVelocity().LengthSqr() >= 80000)
{
	HandleSlidingSpeedCrop();
}
else
{
	// Slow down ducked players.
	HandleDuckingSpeedCrop();
}

void CGameMovement::HandleSlidingSpeedCrop(void)
{
	if (!(m_iSpeedCropped & SPEED_CROPPED_SLIDE) && (player->GetFlags() & FL_DUCKING) && (player->GetGroundEntity() != NULL))
	{

		if (!logic_timer.HasStarted())
		{
			logic_timer.Start(0.5f);
		}
		Msg("%.3f time elapsed\n", logic_timer.GetElapsedTime());

		//if slide timer is over transition to duck
		if (logic_timer.IsElapsed()) {
			Msg("%.3f initiate slide\n", player->GetAbsVelocity().LengthSqr());
			m_iSpeedCropped |= SPEED_CROPPED_DUCK;
			logic_timer.Reset();
		}
		else 
		{
			//Slide crop
			float times = 1.00f;
			float sideSpeed = 0.00f;
			//mv->m_flForwardMove *= times;
			mv->m_flSideMove *= sideSpeed;
			mv->m_flUpMove *= times;
			m_iSpeedCropped |= SPEED_CROPPED_SLIDE;
			//enum: 0 & 1 (bitwise AND)   outputs 0
			//enum: 0 | 1 (bitwise OR)    outputs 1      
		}
	}
}