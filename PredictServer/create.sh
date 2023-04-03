bash
curl -X START_BD \\
curl -X POST \\
  -H "Content-Type: multipart/form-data" \\
  -F "target_no=123" \\
  -F "latitude=45.123" \\
  -F "longitude=-123.456" \\
  -F "image=@objects/0.png" \\
  -F "time=2021-01-01 12:34:56" \\
  http://localhost:5000/targets