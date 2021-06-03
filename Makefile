Srcs=ShipmentManager.cpp OrdersDB.cpp DriversDB.cpp Order.cpp Driver.cpp
Hdrs=ShipmentManager.hpp OrdersDB.hpp DriversDB.hpp Order.hpp Driver.hpp

all:
	g++-9 -g -Wall -Wextra -Wpedantic main.cpp  ${Srcs} -o shipmentManager

files:
	touch ${Srcs} ${Hdrs}
