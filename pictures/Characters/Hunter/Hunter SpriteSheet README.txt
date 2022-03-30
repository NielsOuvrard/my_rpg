Hunter Spritesheet
#----------------------------#
| Image type: .png           |
| Frame Width: 16            |
| Frame Height: 16           |
| Total Image size: 8.47 KB  |
#----------------------------#

Animations:
	-Run Up
	-Run Down
	-Run Left
	-Run Right
	-Idle Left
	-Idle Right
	-Idle Up
	-Idle Down
	-Bow Drawn Left
	-Bow Released Left
	-Bow Drawn Right
	-Bow Released Right

#----------------------------------------------------#
| Go through each frame in the order specified in order|
| to produce an animation				     |
#----------------------------------------------------#
	Up:
		Loop the frames A-B-A-C on row 1.
	Idle up:
		Loop the frame A on row 1.
#----------------------------------------------------#
	Down:
		Loop the frames A-B-A-C on row 2.
	Idle down:
		Loop the frame A on row 2.
#----------------------------------------------------#
	Left:
		Loop the frames A-B-C-A-D-E on row 3.
	Idle Left:
		Loop the frame F on row 3.
#----------------------------------------------------#
	Right:
		Loop the frames A-B-C-A-D-E on row 4.
	Idle Right:
		Loop the frame F on row 4.		
#----------------------------------------------------#
	Bow Drawn Left:
		Loop the frames A-B on row 5.
	Bow Released Left:	
		Loop the frames C-D on row 5.
#----------------------------------------------------#
	Bow Drawn Right:
		Loop the frames A-B on row 6.
	Bow Released Right:
		Loop the frames C-D on row 6.
#----------------------------------------------------#


	