// Ducking
virtual void	Duck( void );
virtual void	HandleDuckingSpeedCrop();
virtual void	HandleSlidingSpeedCrop();

//Slide timer
CountdownTimer logic_timer; 

//walking and jumping
virtual void	FullWalkMove();
int DoubleJumpCounter = 1;