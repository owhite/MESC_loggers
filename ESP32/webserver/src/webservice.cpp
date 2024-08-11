#include <WiFi.h>
#include "index_html.h"
#include "webservice.h"
#include "global.h"
#include "blink.h"

char bigString[] = "{\"time\":[0.000000,0.000050,0.000100,0.000150,0.000200,0.000250,0.000300,0.000350,0.000400,0.000450,0.000500,0.000550,0.000600,0.000650,0.000700,0.000750,0.000800,0.000850,0.000900,0.000950,0.001000,0.001050,0.001100,0.001150,0.001200,0.001250,0.001300,0.001350,0.001400,0.001450,0.001500,0.001550,0.001600,0.001650,0.001700,0.001750,0.001800,0.001850,0.001900,0.001950,0.002000,0.002050,0.002100,0.002150,0.002200,0.002250,0.002300,0.002350,0.002400,0.002450,0.002500,0.002550,0.002600,0.002650,0.002700,0.002750,0.002800,0.002850,0.002900,0.002950,0.003000,0.003050,0.003100,0.003150,0.003200,0.003250,0.003300,0.003350,0.003400,0.003450,0.003500,0.003550,0.003600,0.003650,0.003700,0.003750,0.003800,0.003850,0.003900,0.003950,0.004000,0.004050,0.004100,0.004150,0.004200,0.004250,0.004300,0.004350,0.004400,0.004450,0.004500,0.004550,0.004600,0.004650,0.004700,0.004750,0.004800,0.004850,0.004900,0.004950],\"Vbus.V.y1\":[54.34,54.31,54.23,54.31,54.27,54.23,54.23,54.23,54.12,54.16,54.19,54.31,54.19,54.23,54.23,54.31,54.23,54.16,54.19,54.23,54.34,54.23,54.23,54.19,54.19,54.19,54.19,54.27,54.16,54.19,54.23,54.27,54.31,54.23,54.19,54.27,54.23,54.31,54.27,54.23,54.31,54.31,54.42,54.23,54.31,54.23,54.19,54.31,54.23,54.27,54.19,54.38,54.31,54.42,54.19,54.23,54.31,54.27,54.31,54.31,54.27,54.31,54.42,54.38,54.31,54.27,54.31,54.23,54.31,54.61,54.31,54.34,54.34,54.34,54.38,54.27,54.27,54.34,54.23,54.16,54.27,54.27,54.31,54.23,54.31,54.19,54.19,54.23,54.19,54.12,54.19,54.19,54.27,54.27,54.34,54.34,54.23,54.27,54.23,54.31],\"Iu.I_phase.y1\":[0.99,0.99,3.08,2.61,1.68,1.68,-0.41,-0.18,-0.64,0.29,-1.11,-0.41,0.29,1.45,1.22,0.75,0.06,0.99,0.52,0.99,0.29,0.52,0.06,1.68,1.22,0.29,0.99,-0.64,0.29,0.06,0.99,0.75,0.06,0.29,0.29,0.75,0.99,-0.87,-1.34,-2.04,-1.34,-1.57,-1.34,-1.80,0.75,0.75,0.29,0.52,-1.11,0.29,-0.41,0.29,0.52,-0.18,0.06,0.29,0.52,1.45,0.29,0.06,-0.41,0.29,-0.18,0.52,-0.41,0.52,0.29,0.29,0.06,-0.64,0.06,-0.41,0.29,0.52,0.06,1.68,1.45,1.45,2.61,-0.41,-1.11,-2.50,-1.57,-1.34,-1.34,-1.11,0.52,0.52,-0.41,0.29,0.52,0.75,0.75,0.52,0.52,0.06,1.45,0.99,1.22,2.15],\"Iv.I_phase.y1\":[-0.18,-0.65,-0.65,0.05,-0.41,-0.88,0.75,-0.41,0.05,-0.41,0.75,0.28,0.52,1.68,2.38,2.14,2.14,1.21,0.28,0.75,-0.88,-0.65,-0.18,0.28,0.28,0.05,-0.41,1.21,0.05,0.28,-1.34,-0.41,-0.18,-0.41,-0.41,0.52,-1.58,0.98,0.98,0.05,0.28,0.98,2.61,1.45,1.45,1.21,-0.41,-0.88,0.52,-0.18,0.05,-2.27,-1.81,-0.65,0.05,0.05,0.28,-1.81,0.05,-0.65,-0.88,-0.41,-0.88,-0.65,-0.41,-0.18,0.28,-0.88,0.28,0.98,0.28,0.98,-1.11,-0.41,-0.65,-0.88,-1.34,-1.81,-4.13,0.05,-0.41,-0.65,-0.88,0.05,1.21,0.75,0.98,1.91,0.98,1.21,0.98,0.05,0.98,-0.88,-0.65,-0.65,-0.18,0.05,0.05,-1.34],\"Iw.I_phase.y1\":[-0.24,-1.64,-1.87,-2.34,-1.17,-0.01,-0.24,1.38,0.45,1.38,-0.01,-0.71,-0.24,-2.34,-2.57,-2.10,-1.41,-1.41,-1.41,-0.24,-0.01,0.22,-1.17,-1.87,-1.64,-0.94,-0.48,-0.24,-0.01,-1.64,0.45,-0.01,-0.71,0.92,-1.41,-0.01,0.45,0.45,1.38,1.38,2.08,-0.01,0.22,-0.01,-2.57,-1.87,-0.01,-0.24,0.22,0.69,0.69,2.08,1.85,0.22,0.69,-0.94,-0.01,0.45,-0.01,0.45,0.22,1.38,0.92,0.92,-0.01,-1.17,-0.01,0.22,-0.01,0.22,0.22,-0.24,-0.01,0.69,-0.71,-0.01,-1.17,0.92,1.38,0.92,2.31,2.08,3.71,1.38,1.15,0.45,-1.87,-1.87,-1.41,-0.94,-0.94,-1.17,-0.94,-0.01,0.22,-0.71,-0.48,-1.87,-0.71,-0.24],\"Vd.V_dq.y1\":[8.79,8.96,8.74,8.55,8.29,8.25,8.52,8.90,8.57,8.67,8.33,8.51,8.64,9.01,8.94,8.46,8.41,8.28,8.30,8.48,8.56,8.62,8.83,8.84,8.61,8.44,8.36,8.54,8.59,8.50,8.87,8.76,8.58,8.40,8.54,8.71,8.37,8.74,8.87,8.58,8.44,8.22,8.51,8.50,8.89,8.72,8.48,8.47,8.65,8.80,8.58,8.87,8.65,8.45,8.49,8.63,8.67,8.28,8.55,8.70,8.57,8.68,8.57,8.65,8.59,8.68,8.67,8.52,8.59,8.66,8.67,8.38,8.74,8.71,8.82,8.54,8.33,8.24,8.04,8.65,9.06,8.85,8.57,8.29,8.39,8.50,8.80,8.93,8.77,8.47,8.38,8.38,8.39,8.64,8.65,8.77,8.63,8.59,8.50,8.12],\"Vq.V_dq.y1\":[28.28,27.92,27.69,27.63,27.98,28.50,28.07,28.23,28.06,28.19,28.31,28.32,28.34,27.93,27.68,27.75,27.88,28.28,28.36,28.53,28.06,28.10,28.03,27.84,27.80,27.99,28.24,27.98,28.25,28.24,28.10,28.17,28.17,28.29,27.78,28.21,28.47,28.12,28.00,27.74,27.91,28.18,28.52,28.53,27.95,27.88,28.26,28.29,28.00,28.32,28.16,27.75,27.80,28.09,28.36,27.98,28.21,28.54,28.32,28.32,28.18,28.26,28.02,28.12,28.15,27.93,28.26,28.34,28.28,28.14,28.29,28.32,28.07,28.21,28.05,28.05,27.76,28.44,28.66,28.40,28.20,27.61,27.71,28.07,28.53,28.53,28.01,27.93,27.86,28.08,28.25,28.43,28.56,28.18,28.17,28.06,28.14,27.79,28.09,28.54],\"angle.misc.y1\":[36961,43227,49412,55523,61827,2753,8601,14941,21194,27601,34023,40373,46805,52904,58982,65105,5738,12121,18373,24880,30896,37329,43626,49768,55995,62284,3079,9063,15506,21802,28014,34387,40671,47057,52961,59529,486,6538,12786,18816,25016,31291,37926,44147,50110,56422,62973,3712,9751,16260,22546,28576,34812,41102,47409,53304,59649,587,6704,13097,19392,25797,31948,38279,44545,50602,57042,63320,4005,10183,16575,22935,29073,35505,41639,47848,53731,60346,1539,7456,13893,19897,26145,32462,38949,45264,51254,57490,63598,4372,10620,16969,23424,29482,35882,42127,48466,54434,60810,1791]}";

void initWebService(HardwareSerial& compSerial, HardwareSerial& mescSerial, AsyncWebServer& server, AsyncWebSocket& webSocket) {

  g_compSerial = &compSerial;
  g_mescSerial = &mescSerial;
  g_webSocket = &webSocket;

  // Ensure config object is initialized before using it
  if (strlen(config.password) == 0) {
    g_compSerial->println("WiFi password not set!");
    return;
  }

  // Use explicit casts to resolve ambiguity
  WiFi.begin((const char*)config.ssid, (const char*)config.password);

  g_compSerial->print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    g_compSerial->print(".");
  }

  g_compSerial->println("");
  g_compSerial->println("WiFi connected");
  g_compSerial->print("IP address: ");
  g_compSerial->println(WiFi.localIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    handleRoot(request);
  });

  server.on("/button", HTTP_GET, [](AsyncWebServerRequest *request) {
    handleButtonPress(request);
  });

  server.addHandler(&webSocket);  // Attach WebSocket to server
  server.begin();
  g_compSerial->println("HTTP server started");
  setBlinkSpeed(80);

  webSocket.onEvent([](AsyncWebSocket* server, AsyncWebSocketClient* client, AwsEventType type, void* arg, uint8_t* data, size_t len) {
    switch (type) {
    case WS_EVT_DISCONNECT:
      g_compSerial->printf("[%u] Disconnected!\n", client->id());
      break;
    case WS_EVT_CONNECT:
      g_compSerial->printf("[%u] Connected!\n", client->id());
      break;
    case WS_EVT_DATA:
      handleWebSocketMessage(client, data, len);
      break;
    case WS_EVT_PONG:
      g_compSerial->printf("[%u] Pong received\n", client->id());
      break;
    case WS_EVT_ERROR:
      g_compSerial->printf("[%u] Error\n", client->id());
      break;
    default:
      break;
    }
  });

  xTaskCreate(webServerTask, "Web Server Task", 8192, NULL, 1, NULL);
}

void handleWebSocketMessage(AsyncWebSocketClient* client, uint8_t *data, size_t len) {
    data[len] = '\0'; // Null-terminate the string
    const char* message = (char*)data;

    if (strcmp(message, "IP") == 0) {
        g_compSerial->println("IP address: ");
        g_compSerial->println(WiFi.localIP());
    }
    else if (strcmp(message, "log_request") == 0) {
        g_compSerial->println("log requested ");
	g_webSocket->textAll(bigString);

    }
    else {
      g_compSerial->printf("WebSocket message: %s\n", message);
      g_mescSerial->write(message);
      g_mescSerial->write("\r\n");
    }
}

void webServerTask(void *pvParameter) {
  while (1) {
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}

void handleRoot(AsyncWebServerRequest *request) {
  // Serve the HTML content from PROGMEM
  request->send_P(200, "text/html", index_html);
}

void handleButtonPress(AsyncWebServerRequest *request) {
  g_compSerial->println("Update requested");
  processButtonPress();
  request->send(200, "text/plain", "Update requested");
}

void processButtonPress() {
  g_compSerial->println("Running get.");
  g_mescSerial->write("get\r\n");

  commState = COMM_GET;
}
