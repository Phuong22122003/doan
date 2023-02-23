from gtts import gTTS
import pygame
import speech_recognition as sr


# create a recognizer object
r = sr.Recognizer()

# use the default microphone as the audio source
with sr.Microphone() as source:
    print("Say something!")
    audio = r.listen(source)

# recognize speech using Google Speech Recognition
try:
    text = r.recognize_google(audio)
    print("Google Speech Recognition thinks you said: " + text)

    # convert text to speech using gTTS
    tts = gTTS(text=text, lang='en')
    tts.save('output.mp3')

    # play the audio file using pygame
    pygame.mixer.init()
    pygame.mixer.music.load("output.mp3")
    pygame.mixer.music.play()
    while pygame.mixer.music.get_busy():
        continue

except sr.UnknownValueError:
    print("Google Speech Recognition could not understand audio")
except sr.RequestError as e:
    print("Could not request results from Google Speech Recognition service; {0}".format(e))
