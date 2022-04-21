#ifndef POS_CONTROLLER_H
#define POS_CONTROLLER_H

#include "../lib/forecastnucleoframework/include/forecast/Controller.hpp"

namespace forecast
{

    /**
     * @brief Pos Control class
     **/
    class PosController : public Controller
    {
    public:
        /**
         * @brief Pos control constructor
         **/
        PosController();
        /**
     * @brief Construct a new Pos object. This constructor
    initialize,
     * the controller.
     * @param p_kp
     * @param p_kd
     * @param p_ki

    **/
        PosController(float p_kp, float p_kd, float p_ki);

        /**
         * @brief Pos control initialization
         *
         * @param a vector containing the constants KP , K_DES
         * in this order
         **/
        virtual bool init(const std::vector<float> &params) override;
        /**
         * @brief Get Return the names of the parameters.
         *
         * @return std::vector<std::string>
         */
        virtual std::vector<std::string> getParamNames() const override;

        virtual float process(const IHardware *hw,
                              float ref,
                              float dref = 0,
                              float ddref = 0) override;

    protected:
        float p_kp = 0.0f;
        float p_kd = 0.0f;
        float p_ki = 0.0f;

        bool once = true;

        float theta = 0.0f;

        float err = 0.0;
        float derr = 0.0;
        float ierr = 0.0;

        float errPast = 0.0;

        float out;
    };
} // namespace forecast

#endif // POS_CONTROLLER_H
