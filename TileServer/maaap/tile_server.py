import http.server
import socketserver

class TileServerRequestHandler(http.server.SimpleHTTPRequestHandler):
    def do_GET(self):
        tile_name_parts = self.path.split('/')
        if len(tile_name_parts) == 4 and tile_name_parts[-1].endswith('.png'):
            self.path = '/tiles/{}/{}_{}'.format(tile_name_parts[1], tile_name_parts[2], tile_name_parts[3])
        return http.server.SimpleHTTPRequestHandler.do_GET(self)

my_server = socketserver.TCPServer(("127.0.0.1", 80), TileServerRequestHandler)
my_server.serve_forever()