#include "Network.h"
#include <memory>

namespace traffic_model {

    class Vehicle;
    class Lane;
    class LaneChange {
        friend class Vehicle;
     protected:
        struct signal {
            int direction;
            Lane * target;
            Vehicle * source;
            int response = 0;
        };
        Vehicle * vehicle;

        double leaderGap;
        double followerGap;
        double waitingTime = 0;

        bool changing = false;
        bool finished = false;
        double lastChangeTime = 0;

        static constexpr double coolingTime = 3;

    public:
        LaneChange(Vehicle * vehicle, const LaneChange &other);

        explicit LaneChange(Vehicle * vehicle) : vehicle(vehicle) {};

        virtual ~LaneChange() = default;

        Lane *getTarget() const;

        double gapBefore() const ;

        double gapAfter() const ;

        virtual double safeGapBefore() const = 0;
        virtual double safeGapAfter() const = 0;

        bool planChange() const;

        bool canChange() const { return signalSend && !signalRecv; }

        bool isGapValid() const { return gapAfter() >= safeGapAfter() && gapBefore() >= safeGapBefore(); }

        void finishChanging();

        void abortChanging();

        virtual double yieldSpeed(double interval) = 0;

        virtual void sendSignal() = 0;

        int getDirection();

        void clearSignal();

        bool hasFinished() const { return this->finished; }

    };

    class SimpleLaneChange : public LaneChange {
    private:
        double estimateGap(const Lane *lane) const;
    public:
        explicit SimpleLaneChange(Vehicle * vehicle) : LaneChange(vehicle) {};
        explicit SimpleLaneChange(Vehicle * vehicle, const LaneChange &other) : LaneChange(vehicle, other) {};

        void makeSignal(double interval) override;
        void sendSignal() override;

        double yieldSpeed(double interval) override;

        double safeGapBefore() const override;

        double safeGapAfter() const override;

    };
}
