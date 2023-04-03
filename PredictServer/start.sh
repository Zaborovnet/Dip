bash
curl -X POST \
  -H "Content-Type: multipart/form-data" \
  -F "number=123" \
  -F "longitude=45.123" \
  -F "latitude=-123.456" \
  -F "image=@/objects/0.png" \
  -F "time=2021-01-01 12:34:56" \
  http://127.0.0.1:5000/

curl http://127.0.0.1:5000/



