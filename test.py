import http.client

conn = http.client.HTTPSConnection("carbonsutra1.p.rapidapi.com")

payload = "iata_airport_from=LAX&iata_airport_to=SIN&flight_class=economy&round_trip=Y&add_rf=N&include_wtt=N&number_of_passengers=1"

headers = {
    'content-type': "application/x-www-form-urlencoded",
    'Authorization': "Bearer <AUTHORIZATION_TOKEN>",
    'X-RapidAPI-Key': "<AUTHORIZATION_KEY>",
    'X-RapidAPI-Host': "carbonsutra1.p.rapidapi.com"
    }

conn.request("POST", "/flight_estimate", payload, headers)

res = conn.getresponse()
data = res.read()

print(data.decode("utf-8"))
print(data.decode("utf-8"))