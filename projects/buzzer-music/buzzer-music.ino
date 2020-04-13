
#include "./melody.h"
#include "./notes.h"

int speakerPin = 13;

// Register melodies
int ttlsNotes[] = { NOTE_C6, NOTE_C6, NOTE_G6, NOTE_G6, NOTE_A6, NOTE_A6, NOTE_G6, 
                    NOTE_F6, NOTE_F6, NOTE_E6, NOTE_E6, NOTE_D6, NOTE_D6, NOTE_C6, 0 }; // Zero ( 0 ) represents a rest
int ttlsBeats[] = { 1, 1, 1, 1, 1, 1, 2, 
                    1, 1, 1, 1, 1, 1, 2, 4 };
int ttlsTempo = 300;
Melody ttls = Melody("Twinkle Twinkle Little Star", 15,  ttlsNotes, ttlsBeats, ttlsTempo);

int hbtyNotes[] = { NOTE_C6, NOTE_C6, NOTE_D6, NOTE_C6, NOTE_F6, NOTE_E6,
                    NOTE_C6, NOTE_C6, NOTE_D6, NOTE_C6, NOTE_G6, NOTE_E6, // E7?
                    NOTE_C6, NOTE_C6, NOTE_C7, NOTE_A6, NOTE_F6, NOTE_E6, NOTE_D6,
                    NOTE_AS6, NOTE_AS6, NOTE_A6, NOTE_F6, NOTE_G6, NOTE_F6, 0 };
int hbtyBeats[] = { 1, 1, 1, 1, 1, 2,
                    1, 1, 1, 1, 1, 2,
                    1, 1, 1, 1, 1, 1, 2, 
                    1, 1, 1, 1, 1, 2, 4 };
int hbtyTempo = 300;
Melody hbty = Melody("Happy Birthday To You", 26, hbtyNotes, hbtyBeats, hbtyTempo);

int jvedtNotes[] = { NOTE_F4, NOTE_DS4, NOTE_D4, NOTE_C4, NOTE_AS3, NOTE_C4, NOTE_D4, 
                     NOTE_DS4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_DS4, NOTE_D4, 0 };
int jvedtBeats[] = { 3, 1, 2, 2, 2, 2, 2, 
                     2, 3, 1, 2, 2, 4, 4 };
int jvedtTempo = 300;
Melody jvedt = Melody("Ja Vi Elsker Dette Landet (National Anthem of Norway)", 14, jvedtNotes, jvedtBeats, jvedtTempo);

int tomNotes[] = { NOTE_FS5, NOTE_FS5, NOTE_D5, NOTE_B4, 0, NOTE_B4, 
                   0, NOTE_E5, 0, NOTE_E5, 0, NOTE_E5, 
                   NOTE_GS5, NOTE_GS5, NOTE_A5, NOTE_B5, NOTE_A5, NOTE_A5, 
                   NOTE_A5, NOTE_E5, 0, NOTE_D5, 0, NOTE_FS5, 
                   0, NOTE_FS5, 0, NOTE_FS5, NOTE_E5, NOTE_E5, 
                   NOTE_FS5, NOTE_E5 };
int tomBeats[] = { 1, 1, 1, 1, 1, 1,
                   1, 1, 1, 1, 1, 1,
                   1, 1, 1, 1, 1, 1,
                   1, 1, 1, 1, 1, 1,
                   1, 1, 1, 1, 1, 1,
                   1, 1 };
int tomTempo = 135;
Melody tom = Melody("Take On Me", 32, tomNotes, tomBeats, tomTempo);

int asTrebNotes[] = { NOTE_C6, 0, // Signal start and synchronization
                      NOTE_FS4, NOTE_CS5, NOTE_AS4, NOTE_AS4, NOTE_GS4, NOTE_FS4, 
                      NOTE_FS4, NOTE_B4, NOTE_AS4, NOTE_AS4, NOTE_GS4, NOTE_GS4, 
                      NOTE_FS4, NOTE_FS4, NOTE_CS5, NOTE_AS4, NOTE_AS4, NOTE_GS4, 
                      NOTE_FS4, NOTE_FS4, NOTE_DS4, NOTE_CS4, 0, NOTE_FS4, 
                      NOTE_FS4, NOTE_CS5, NOTE_AS4, NOTE_AS4, NOTE_GS4, NOTE_GS4, 
                      NOTE_FS4, NOTE_FS4, NOTE_B4, NOTE_AS4, NOTE_AS4, NOTE_GS4, 
                      NOTE_GS4, NOTE_FS4, NOTE_FS4, NOTE_CS5, NOTE_AS4, NOTE_AS4, 
                      NOTE_GS4, NOTE_FS4, NOTE_FS4, NOTE_GS4, NOTE_DS4, 0 };
int asTrebBeats[] = { 1, 4, 
                      2, 1, 1, 2, 1, 1, 
                      1, 2, 1, 1, 1, 1, 
                      2, 1, 1, 1, 2, 1,
                      1, 1, 2, 3, 2, 1,
                      1, 1, 1, 1, 1, 1,
                      1, 1, 2, 1, 1, 1,
                      1, 1, 1, 2, 1, 1, 
                      2, 1, 1, 2, 3, 4 };
int asTempo = 250;
Melody asTreb = Melody("All Star (Treble)", 50, asTrebNotes, asTrebBeats, asTempo);

int asBassNotes[] = { NOTE_C6, 0, // Signal start and synchronization
                      0, NOTE_FS2, NOTE_CS3, NOTE_GS2, NOTE_B2, 
                      NOTE_FS2, NOTE_CS3, NOTE_GS2, NOTE_B2, 
                      NOTE_FS2, NOTE_CS3, NOTE_GS2, NOTE_B2, 
                      NOTE_FS2, NOTE_CS3, NOTE_GS2, 0 };
int asBassBeats[] = { 1, 4, 
                      2, 4, 4, 4, 4,
                      4, 4, 4, 4, 
                      4, 4, 4, 4,
                      4, 4, 4, 4 };
Melody asBass = Melody("All Star (Bass)", 18, asBassNotes, asBassBeats, asTempo);

void setup() 
{
  Serial.begin(9600);
  
  pinMode(speakerPin, OUTPUT);
}

void loop() 
{
  play(ttls);
  delay(1000);
  play(hbty);
  delay(1000);
  play(jvedt);
  delay(1000);
  play(tom);
  delay(1000);
  play(asTreb);
  delay(1000);
  //play(asBass);
  //delay(1000);
}

void play(Melody m)
{
  String mName = m.getMelodyName();
  int mLength = m.getMelodyLength();
  int* notes = m.getNotes();
  int* beats = m.getBeats();
  int tempo = m.getTempo();
  
  Serial.print("Now playing: ");
  Serial.println(mName);

  for (int i = 0; i < mLength; i++) 
  {
    // Rest/Pause
    if (notes[i] == 0) 
    {
      delay(beats[i] * tempo);
      continue;
    }

    // Play tone, wait, stop tone
    tone(speakerPin, notes[i], beats[i] * tempo);
    delay(beats[i] * tempo);
    noTone(speakerPin);

    // pause between notes
    delay(tempo / 2); 
  }
} 

void playTone(int tone, int duration) 
{
  for (long i = 0; i < duration * 1000L; i += tone * 2) 
  {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}
