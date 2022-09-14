# Transport Catalogue
Транспортный справочник.
Реализует функционал транспортного справочника с  возможностью визуализации карты маршрутов в формате SVG.
![Image alt](https://github.com/1grMd/cpp-transport-catalogue/blob/main/transport-catalogue/map.svg)
Данные поступают в формате JSON-объекта. Его верхнеуровневая структура:
{
  "base_requests": [ ... ],
  "stat_requests": [ ... ]
}
Это словарь, содержащий ключи:
base_requests — массив с описанием автобусных маршрутов и остановок,
stat_requests — массив с запросами к транспортному справочнику.
Массив base_requests содержит элементы двух типов: маршруты и остановки. Они перечисляются в произвольном порядке.
Пример описания остановки:
{
  "type": "Stop",
  "name": "Электросети",
  "latitude": 43.598701,
  "longitude": 39.730623,
  "road_distances": {
    "Улица Докучаева": 3000,
    "Улица Лизы Чайкиной": 4300
  }
}
Пример описания автобусного маршрута:
{
  "type": "Bus",
  "name": "14",
  "stops": [
    "Улица Лизы Чайкиной",
    "Электросети",
    "Улица Докучаева",
    "Улица Лизы Чайкиной"
  ],
  "is_roundtrip": true
}
Вывод производится в выходной JSON-массив
Получение информации о маршруте
Формат запроса:
{
  "id": 12345678,
  "type": "Bus",
  "name": "14"
}
Возможный ответ:
{
  "curvature": 2.18604,
  "request_id": 12345678,
  "route_length": 9300,
  "stop_count": 4,
  "unique_stop_count": 3
}
Получение информации об остановке
Формат запроса:
{
  "id": 12345,
  "type": "Stop",
  "name": "Улица Докучаева"
} 
Ответ на запрос:
{
  "buses": [
      "14", "22к"
  ],
  "request_id": 12345
}
Запрос на рендеринг карты:
{
  "type": "Map",
  "id": 11111
}
Ответ на этот запрос отдаётся в виде словаря с ключами request_id и map:
{
  "map": "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>\n<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n  <polyline points=\"100.817,170 30,30 100.817,170\" fill=\"none\" stroke=\"green\" stroke-width=\"14\" stroke-linecap=\"round\" stroke-linejoin=\"round\"/>\n  <text fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" x=\"100.817\" y=\"170\" dx=\"7\" dy=\"15\" font-size=\"20\" font-family=\"Verdana\" font-weight=\"bold\">114</text>\n  <text fill=\"green\" x=\"100.817\" y=\"170\" dx=\"7\" dy=\"15\" font-size=\"20\" font-family=\"Verdana\" font-weight=\"bold\">114</text>\n  <text fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" x=\"30\" y=\"30\" dx=\"7\" dy=\"15\" font-size=\"20\" font-family=\"Verdana\" font-weight=\"bold\">114</text>\n  <text fill=\"green\" x=\"30\" y=\"30\" dx=\"7\" dy=\"15\" font-size=\"20\" font-family=\"Verdana\" font-weight=\"bold\">114</text>\n  <circle cx=\"100.817\" cy=\"170\" r=\"5\" fill=\"white\"/>\n  <circle cx=\"30\" cy=\"30\" r=\"5\" fill=\"white\"/>\n  <text fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" x=\"100.817\" y=\"170\" dx=\"7\" dy=\"-3\" font-size=\"20\" font-family=\"Verdana\">Морской вокзал</text>\n  <text fill=\"black\" x=\"100.817\" y=\"170\" dx=\"7\" dy=\"-3\" font-size=\"20\" font-family=\"Verdana\">Морской вокзал</text>\n  <text fill=\"rgba(255,255,255,0.85)\" stroke=\"rgba(255,255,255,0.85)\" stroke-width=\"3\" stroke-linecap=\"round\" stroke-linejoin=\"round\" x=\"30\" y=\"30\" dx=\"7\" dy=\"-3\" font-size=\"20\" font-family=\"Verdana\">Ривьерский мост</text>\n  <text fill=\"black\" x=\"30\" y=\"30\" dx=\"7\" dy=\"-3\" font-size=\"20\" font-family=\"Verdana\">Ривьерский мост</text>\n</svg>",
  "request_id": 11111
}
