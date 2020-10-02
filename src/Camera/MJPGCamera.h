#include "Camera.h"
#include <gst/gst.h>

class MJPGCamera : public Camera
{
protected:
    GstElement *encoder;
    GstElement *capsfilter;
    string encoder_name;
    guint32 bitrate;
    virtual bool read_configuration(Setting &camera_config, Setting &quality_config) override;

public:
    MJPGCamera(string device, Quality q);
    virtual bool set_element_references(GstElement *pipeline) override;
    virtual bool set_bitrate(guint32 _bitrate) override;
    virtual bool set_quality(Quality q) override;
    virtual string generate_launch_string() const override;
    virtual void improve_quality(bool congested) override;
    virtual void degrade_quality(bool congested) override;
};