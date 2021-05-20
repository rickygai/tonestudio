#ifndef __PITCH_H__
#define __PITCH_H__

// A melody in music is a simple collection of musical notes that is sonically pleasing.
typedef struct
{
    float frequency;
    int   duration;
}
_MELODY;

typedef struct
{
    char  chord[5];
    float frequency;
    int   duration;
}
_MELODYEX;

#endif // __PITCH_H__