#ifndef deteriorate_lv__granulator_stereo_ttl_hpp
#define deteriorate_lv__granulator_stereo_ttl_hpp


#ifndef PEG_STRUCT
#define PEG_STRUCT
typedef struct {
  float min;
  float max;
  float default_value;
  char toggled;
  char integer;
  char logarithmic;
} peg_data_t;
#endif

/* <http://github.com/blablack/deteriorate.lv2/granulator_stereo> */

static const char p_uri[] = "http://github.com/blablack/deteriorate.lv2/granulator_stereo";

enum p_port_enum {
  p_inputL,
  p_inputR,
  p_inputGain,
  p_grainSize,
  p_attack,
  p_release,
  p_grainDensity,
  p_grainSpread,
  p_outputGain,
  p_outputL,
  p_outputR,
  p_n_ports
};

static const peg_data_t p_ports[] = {
  { -3.40282e+38, 3.40282e+38, -3.40282e+38, 0, 0, 0 }, 
  { -3.40282e+38, 3.40282e+38, -3.40282e+38, 0, 0, 0 }, 
  { -10, 10, 1, 0, 0, 0 }, 
  { 6, 10000, 10, 0, 0, 0 }, 
  { 3, 100, 4, 0, 0, 0 }, 
  { 3, 100, 4, 0, 0, 0 }, 
  { 1, 10000, 10, 0, 0, 0 }, 
  { 2, 10000, 100, 0, 0, 0 }, 
  { -10, 10, 1, 0, 0, 0 }, 
  { -3.40282e+38, 3.40282e+38, -3.40282e+38, 0, 0, 0 }, 
  { -3.40282e+38, 3.40282e+38, -3.40282e+38, 0, 0, 0 }, 
};


#endif /* deteriorate_lv__granulator_stereo_ttl_hpp */
