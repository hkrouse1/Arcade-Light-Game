# Acrcade Light Game


## A light pattern game, that gets increasingly more difficult as you beat each level. 
In order to progress, the left button must be hit when the 10th LED is lit. This must happen while the A1 pin is being held. If this is not completed a midi tone will beep a few times and the words "You lose. Your score was" will be displayed in the serial monitor.The score will be dsiplayed aswell. If the level is progressed, the score will go up, and a nice few tones will play. The speed of the LED's ligthing up will increase aswell. This same process will be done over and over again for a total of 4 levels. When the final level is completed, the serial monitor will display the words "You won here is your score:" and then display the score. The cpx board will use a voice command to say "You Win" and a midi song will be played. Then the game will reset and run again. 
