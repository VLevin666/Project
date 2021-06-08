Srcs=Menu.cpp ShipmentManager.cpp OrdersDB.cpp DriversDB.cpp Order.cpp Driver.cpp
Hdrs=Menu.hpp ShipmentManager.hpp OrdersDB.hpp DriversDB.hpp Order.hpp Driver.hpp

all:
	g++-9 -g -Wall -Wextra -Wpedantic main.cpp  ${Srcs} -o shipmentManager -fsanitize=address

files:
	touch ${Srcs} ${Hdrs}
