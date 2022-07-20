#include "Figure.h"

int a = 0, b = 0, c = 0, A = 0, B = 0, C = 0;

	Figure::Figure() {

	}

	std::string Figure::figure_name() {
		return figure + ": ";
	}

    std::string Figure::get_side() {
		return "";
	}

    std::string Figure::get_angle() {
		return "";
	}
