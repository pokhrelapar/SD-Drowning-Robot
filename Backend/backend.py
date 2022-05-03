from http.server import BaseHTTPRequestHandler, HTTPServer
import logging
import json
import * from ArduinoComms

def parseRequest(data_string):
	handle_request(data_string)
	return

class Server(BaseHTTPRequestHandler):
	def _send_cors_headers(self):
		self.send_header("Access-Control-Allow-Origin", "*")
		self.send_header("Access-Control-Allow-Methods", "GET,POST,OPTIONS")
		self.send_header("Access-Control-Allow-Headers", "x-api-key,Content-Type")
	
	def do_OPTIONS(self):
		self.send_response(200)
		self._send_cors_headers()
		self.end_headers()
	
	def do_POST(self):
		self.send_response(200)
		self._send_cors_headers()
		self.send_header("Content-Type", "application/json")
		self.end_headers()
		
		content_length = int(self.headers['Content-Length'])
		post_data = self.rfile.read(content_length)
		parseRequest(post_data.decode('utf-8'))


def run(server_class=HTTPServer, handler_class=Server, port=9000):
	ip_address = ''
	server_address = (ip_address, port)
	httpd = server_class(server_address, handler_class)
	
	print('Starting up')
	
	try:
		httpd.serve_forever()
	except KeyboardInterrupt:
		pass
	
	print('Closing')
	httpd.server_close()

if __name__ == '__main__':
	from sys import argv
	
	if len(argv) == 2:
		run(port=int(argv[1]))
	else:
		run()