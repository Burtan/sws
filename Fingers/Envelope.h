#ifndef _ENVELOPE_H_
#define _ENVELOPE_H_

#include <vector>
#include <string>


class RprEnvelope;

class RprEnvelopePoint
{
public:
    enum EnvShape { Linear, Square, Slow, FastStart, FastEnd, Bezier };

    RprEnvelopePoint(RprEnvelope *parent = NULL);

    void setTime(double time);
    double time() const;

    void setValue(double value);
    double value() const { return m_parameterValue; }

    EnvShape shape() const { return m_envelopeShape; }
    bool selected() const { return m_selected ; }
    double bezierTension() const { return m_bezierTension; }
    
    bool operator<(const RprEnvelopePoint& rhs) const;
    
    void fromString(const char *stateData);
    std::string toString() const;

private:
    double m_time;
    double m_parameterValue;
    EnvShape m_envelopeShape;
    int m_selUnknown;
    bool m_selected;
    int m_bezierUnknown;
    double m_bezierTension;
    RprEnvelope *m_parent;
};

class RprEnvelopePointOp;
class RprEnvelope
{
public:

    RprEnvelope(TrackEnvelope* env);
    void Write();
    template <typename T>
    void ApplyToPoints(T &op)
    { std::for_each(vPoints.begin(), vPoints.end(), op); }
    std::vector<RprEnvelopePoint>& GetPoints()
    { return vPoints; }

    void Add(RprEnvelopePoint &point);

    double GetMax() { return dParamMax; }
    double GetMin() { return dParamMin; }


    ~RprEnvelope();
private:

    TrackEnvelope* m_env;
    std::string m_szTitle;

    int nParamIndex; // 0-based parameter index, VST top-to-bottom
    double dParamMin; 
    double dParamMax; 
    double dNeutralVal; // neutral or zero value
    /* ACT */
    int nActive; /* 1 or 0 */
    /* VIS */
    int nVisible; /* 1 or 0 */
    int nAutomationInLane; /* 1 or 0 */
    double dVISUnknown;
    /* LANEHEIGHT */
    int nLaneHeight;
    int nLHUnknown;
    /* ARM */
    int nArm;  /* 1 or 0 */
    /* DEFSHAPE */
    int nDefaultShape; /* 0 -> 5 */
    std::vector<RprEnvelopePoint> vPoints;
};

#endif /* _ENVELOPE_H_ */

