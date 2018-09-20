import serial
import speech_recognition as sr

def main():
	r = sr.Recognizer()
	r.dynamic_energy_threshold = False
	while(1):
		with sr.Microphone() as source:                                                                       
			print("Speak:")                                                                                   
			audio = r.listen(source, timeout=3)   

		try:
			current = r.recognize_google(audio)
			print(current)
			exec(commandDict(current))
			if(current == "equals"):
				break
		except sr.UnknownValueError:
			continue
		except sr.RequestError as e:
			continue

def commandDict(toCheck):
	return { 
	"1":"ser.write(b'1')",
	"2":"ser.write(b'2')",
	"3":"ser.write(b'3')",
	"4":"ser.write(b'4')",
	"5":"ser.write(b'5')",
	"6":"ser.write(b'6')",
	"7":"ser.write(b'7')",
	"8":"ser.write(b'8')",
	"9":"ser.write(b'9')",
	"equals":"ser.write(b'e')",
	"Plus":"ser.write(b'+')",
	"minus":"ser.write(b'-')",
	"X":"ser.write(b'*')",
	"/":"ser.write(b'/')"}.get(toCheck, "print('Nah')")

if __name__=="__main__":
	ser = serial.Serial()
	ser.port = "COM5"
	ser.baudrate = 9600
	ser.open()
	main()

