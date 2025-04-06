from flask import Flask, request, jsonify

app = Flask(__name__)

# Route to handle incoming data
@app.route('/api/data', methods=['POST'])
def receive_data():
    data = request.get_json()  # Get JSON data from ESP32

    if not data:
        return jsonify({"status": "error", "message": "No data received"}), 400

    temperature = data.get("temperature")
    humidity = data.get("humidity")

    print(f"Received Data -> Temperature: {temperature}°C, Humidity: {humidity}%")

    # Store data in a file (optional)
    with open("data_log.txt", "a") as file:
        file.write(f"Temperature: {temperature}°C, Humidity: {humidity}%\n")

    return jsonify({"status": "success", "message": "Data received successfully"}), 200

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)
