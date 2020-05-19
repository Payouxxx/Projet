#ifndef MUTABLENUMBER_HPP
#define MUTABLENUMBER_HPP
#include "JSON/JSONImpl.hpp"

/*!
 * @brief The MutableNumber class
 */
class MutableNumber {

public:
    /*!
     * @brief Constructor with new values
     *
     * @param val (double)
     * @param p (mutation probability)
     * @param std (standard deviation and variance)
     * @param Inf (is there a lower bound ?)
     * @param min (lower bound)
     * @param Sup (is there an upper bound ?)
     * @param max (upper bound)
     */
    MutableNumber(double val, double p, double std, bool Inf=false, double min=0, bool Sup=false, double max=0);

    /*!
     * @brief Constructor with values from the app.json file
     * @param config (j::Value)
     */
    MutableNumber(const j::Value &config);

    /*!
     * @brief Default constructor
     */
    MutableNumber() = default;

    /*!
     * @brief access to the value of the MutableNumber
     * @return the value attribute (valeur)
     */
    double get() const;

    /*!
     * @brief modifie the value between min and max (if they are activated)
     * @param new value (double)
     */
    void set(double val);

    /*!
     * @brief random change of the value (between min and max if they are activated)
     */
    void mutate();

    /*!
     * @brief create a new MutableNumber with a value between 0 and 1 (like a probability)
     * @param initialValue
     * @param mutation probability
     * @param sigma (standard deviation variance)
     * @return a MutableNumber
     */
    static MutableNumber probability(double initialValue, double mutationProbability, double sigma);

    /*!
     * @brief create a new MutableNumber with a value between 0 and 1 (like a probability)
     *        and other parameters are taken from the app.json file
     * @param config (j::Value)
     * @return a MutableNumber
     */
    static MutableNumber probability(j::Value const& config);

    /*!
     * @brief create a MutableNumber with a positive value and other parameters are arguments of the method
     *
     * @param initialValue
     * @param mutation probability
     * @param sigma (standard deviation variance)
     * @param hasMax (is there an upper bound ?)
     * @param max (upper bound)
     *
     * @return a MutableNumber
     */
    static MutableNumber positive(double initialValue, double mutationProbability, double sigma, bool hasMax=false, double max=0);

    /*!
     * @brief create a MutableNumber with a positive value and other parameters are taken from the app.json file
     *
     * @param config (j::Value)
     * @param hasMax (is there an upper bound ?)
     * @param max (upper bound)
     *
     * @return a MutableNumber
     */
    static MutableNumber positive(j::Value const& config, bool hasMax=false, double max=0);

private:
    double value;       ///< value of the MutableNumber
    double pMutation;   ///< mutation probability
    double sigma;       ///< standard deviation variance
    bool borneInf;      ///< true = activation of the lower bound
    double min;         ///< lower bound
    bool borneSup;      ///< true = activation of the upper bound
    double max;         ///< upper bound
};

#endif // MUTABLENUMBER_HPP
