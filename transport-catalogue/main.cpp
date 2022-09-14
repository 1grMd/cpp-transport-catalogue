#include "json_reader.h"
#include "map_renderer.h"
#include "request_handler.h"


#include <iostream>
#include <fstream>

int main() {
	using namespace std::string_literals;
	using namespace transport_catalogue;

	std::ifstream in("input.json");
	std::ofstream out("output.json");

	auto doc = json_reader::ReadFromJSON(in);
	TransportCatalogue t_catalogue;

	json_reader::ProcessBaseRequests(t_catalogue, doc);
	renderer::MapRenderer renderer(json_reader::ProcessRenderSettings(doc));
	RequestHandler req_handler(t_catalogue, renderer);
	json_reader::ProcessStatRequests(req_handler, doc, out);
	out.close();
	in.close();

	std::ifstream in1("output.json");
	std::ofstream out2("map.svg");
	doc = json_reader::ReadFromJSON(in1);
	out2 << doc.GetRoot().AsArray()[0].AsMap().at("map").AsString();
}