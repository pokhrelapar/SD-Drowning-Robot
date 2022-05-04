import serial
import time
import json

arduino_controls = serial.Serial(port='/dev/ttyACM0', baudrate=9600, timeout=0.1)

commands = {'Start': 0x10, 'Stop': 0x20, 'Fill': 0x30, 'StopFill': 0x40, 'Spokes': 0x50}

movement_data = {'w': 0x00, 's': 0x01, 'a': 0x02, 'd': 0x03}
fill_data = {('a', False): 0x00, ('a', True): 0x01,
			 ('b', False): 0x02, ('b', True): 0x03,
			 ('c', False): 0x04, ('c', True): 0x05,
			 ('d', False): 0x06, ('d', True): 0x07,
			 ('ab', False): 0x08, ('ab', True): 0x09,
			 ('cd', False): 0x0A, ('cd', True): 0x0B,
			 ('all', False): 0x0C, ('all', True): 0x0D
			}
spokes_data = {False: 0x00, True: 0x01}


def write(command):
	command = chr(command) + '\r'
	arduino_controls.write(bytes(command, 'utf-8'))
	return
	
def make_movement_command(direction):
	command = commands['Start'] | movement_data[direction]
	write(command)
	return

def make_stop_movement_command(direction):
	command = commands['Stop'] | movement_data[direction]
	write(command)
	return

def make_fill_command(tank, fill):
	command = commands['Fill'] | fill_data[(tank,fill)]
	write(command)
	return

def make_stop_fill_command(tank, fill):
	command = commands['StopFill'] | fill_data[(tank,fill)]
	write(command)
	return

def make_spokes_command(state):
	command = commands['Spokes'] | fill_data[state]
	write(command)
	return

def handle_request(request):
	json_string = request[8:len(request)-1]
	d = json.loads(json_string)
	
	action = d['Action']
	
	if action == 'Start':
		make_movement_command(d['Direction'])
	elif action == 'Stop':
		make_stop_movement_command(d['Direction'])
	elif action == 'Fill':
		make_fill_command(d['Tank'], d['Fill'])
	elif action == 'StopFill':
		make_stop_fill_command(d['Tank'], d['Fill'])
	elif action == 'Spokes':
		make_spokes_command(d['State'])
	
	return