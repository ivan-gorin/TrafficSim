#include "Vehicle.h"

namespace traffic_model {
    class Flow {
        private:
            VehicleInfo vehicleTemplate;
            double interval;
            double nowTime = 0;
            double currentTime = 0;
            int startTime = 0;
            int endTime = -1;
            int cnt = 0;
            std::string id;
        public:
            Flow(const VehicleInfo &vehicleTemplate, double timeInterval,
            Engine *engine, int startTime, int endTime, const std::string &id) 
            : vehicleTemplate(vehicleTemplate), interval(timeInterval),
              startTime(startTime), endTime(endTime), engine(engine), id(id) {
                assert(timeInterval >= 1 || (startTime == endTime));
                nowTime = interval;
            }
            void nextStep(double timeInterval);

            std::string getId() const;

            void reset();
        }
    };
}
