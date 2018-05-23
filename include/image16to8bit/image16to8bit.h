#include <nodelet/nodelet.h>
#include <ros/ros.h>

namespace image16to8bit
{

    class Converter : public nodelet::Nodelet
    {
        public:
            virtual void onInit();
    };

}