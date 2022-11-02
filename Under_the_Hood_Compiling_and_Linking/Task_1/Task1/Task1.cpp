#include <iostream>

struct point {
	double m_x;
	double m_y;
	point(double x, double y) {
		m_x = x;
		m_y = y;
	}
};

void print_point(const point& point_object) {
	std::cout << "x: " << point_object.m_x << ", y: "
		<< point_object.m_y << std::endl;
}

int main()
{
	int i;
	for (i = 0; i < 5; i++){
		double a = i;
		point my_point(a, 2 * a);
		print_point(my_point);
	}
	return 0;
}
