#include <iostream>
#include <vector>

namespace traffic_model {
    class Roadnet;
    class Road;
    class Lane;
    class Vehicle;

    class Road {
        friend class Roadnet;
        friend class Lane;
    private:
        std::string id;
        std::vector<Lane> lanes;
    public:
        const std::vector<Lane> &getLanes() const { return lanes; }
        std::vector<Lane> &getLanes() { return lanes; }
        bool connectedToRoad(const Road * road) const;
        void reset();
        double getWidth() const;
        double getLength() const;
    };
}
