/////////////////////////////////////////////////////////////////
//                                                             //
// THE PROGRAM IS PROVIDED AS IS WITH NO WARRANTY OF ANY KIND, //
// INCLUDING THE WARRANTY OF DESIGN, MERCHANTABILITY AND       //
// FITNESS FOR A PARTICULAR PURPOSE.                           //
//                                                             //
// Filename: tone.ino                                          //
//                                                             //
// Function: to demonstrate the Tone Studio composed melody    //
//           C header as part of Arduino sketch speakers       //
//           driver project.                                   //
//                                                             //
//           This program iterates pin 5,6,9 to play tone      //
//           melody respectively.                              //
//                                                             //
/////////////////////////////////////////////////////////////////

#include "pitch.h"
#include "The Twillight Zone.mex.h"
#include "Family Mart.mex.h"

//#define melody The_Twillight_Zone
#define melody Family_Mart

const int max = sizeof( melody ) / sizeof( _MELODYEX );
int n {};
char buf[100]{};

void setup() 
{
    Serial.begin( 9600 );
    Serial.print( "\nsetup()..." );
    sprintf( buf, "\nmax=[%i]", max );
    Serial.print( buf );    
}

const int speaker = 5;
const int active_buzzer = 6;
const int passive_buzzer = 9;
int pin {};
int cnt{};
int spk {-1};

void loop() 
{
    sprintf( buf, "\nloop()...%i", cnt++ );
    Serial.print( buf );

    unsigned int frequency {};
    unsigned long duration {};

    if( spk + 1 < 3 )
       spk++;
    else
       spk = 0;   

    switch( spk )
    {
    case 0: // 8 ohm speaker
        pin = speaker;
        break;

    case 1: // active buzzer
        pin = active_buzzer;
        break;

    case 2:
        pin = passive_buzzer;      
    }

    for( n=0; n<max; n++ ) 
    {
        frequency = (unsigned int)melody[n].frequency;
        duration = (unsigned long)melody[n].duration;
     
        sprintf( buf, "\npin=[%s] chord=[%s] freq=[%i] duration=[%i]", ( pin==speaker ? "speaker" : "buzzer" ), melody[n].chord, (int)frequency, (int)duration );
        
        Serial.print( buf );

        tone( pin, frequency );
        delay( duration );
        noTone( pin );
    }

    delay( 3000 );
}

/// END OF FILE /////////////////////////////////////////////////
