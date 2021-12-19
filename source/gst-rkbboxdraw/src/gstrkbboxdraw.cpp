/* GStreamer
 * Copyright (C) 2021 FIXME <fixme@example.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Suite 500,
 * Boston, MA 02110-1335, USA.
 */
/**
 * SECTION:element-gstrkbboxdraw
 *
 * The rkbboxdraw element does FIXME stuff.
 *
 * <refsect2>
 * <title>Example launch line</title>
 * |[
 * gst-launch-1.0 -v fakesrc ! rkbboxdraw ! FIXME ! fakesink
 * ]|
 * FIXME Describe what the pipeline does.
 * </refsect2>
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gst/gst.h>
#include <gst/video/video.h>
#include <gst/video/gstvideofilter.h>
#include "gstrkbboxdraw.h"

GST_DEBUG_CATEGORY_STATIC (gst_rkbboxdraw_debug_category);
#define GST_CAT_DEFAULT gst_rkbboxdraw_debug_category

/* prototypes */


static void gst_rkbboxdraw_set_property (GObject * object,
    guint property_id, const GValue * value, GParamSpec * pspec);
static void gst_rkbboxdraw_get_property (GObject * object,
    guint property_id, GValue * value, GParamSpec * pspec);
static void gst_rkbboxdraw_dispose (GObject * object);
static void gst_rkbboxdraw_finalize (GObject * object);

static gboolean gst_rkbboxdraw_start (GstBaseTransform * trans);
static gboolean gst_rkbboxdraw_stop (GstBaseTransform * trans);
static gboolean gst_rkbboxdraw_set_info (GstVideoFilter * filter, GstCaps * incaps,
    GstVideoInfo * in_info, GstCaps * outcaps, GstVideoInfo * out_info);
static GstFlowReturn gst_rkbboxdraw_transform_frame (GstVideoFilter * filter,
    GstVideoFrame * inframe, GstVideoFrame * outframe);
static GstFlowReturn gst_rkbboxdraw_transform_frame_ip (GstVideoFilter * filter,
    GstVideoFrame * frame);

enum
{
  PROP_0
};

/* pad templates */

/* FIXME: add/remove formats you can handle */
#define VIDEO_SRC_CAPS \
    GST_VIDEO_CAPS_MAKE("{ RGB }")

/* FIXME: add/remove formats you can handle */
#define VIDEO_SINK_CAPS \
    GST_VIDEO_CAPS_MAKE("{ RGB }")


/* class initialization */

G_DEFINE_TYPE_WITH_CODE (GstRkbboxdraw, gst_rkbboxdraw, GST_TYPE_VIDEO_FILTER,
  GST_DEBUG_CATEGORY_INIT (gst_rkbboxdraw_debug_category, "rkbboxdraw", 0,
  "debug category for rkbboxdraw element"));

static void
gst_rkbboxdraw_class_init (GstRkbboxdrawClass * klass)
{
  GObjectClass *gobject_class = G_OBJECT_CLASS (klass);
  GstBaseTransformClass *base_transform_class = GST_BASE_TRANSFORM_CLASS (klass);
  GstVideoFilterClass *video_filter_class = GST_VIDEO_FILTER_CLASS (klass);

  /* Setting up pads and setting metadata should be moved to
     base_class_init if you intend to subclass this class. */
  gst_element_class_add_pad_template (GST_ELEMENT_CLASS(klass),
      gst_pad_template_new ("src", GST_PAD_SRC, GST_PAD_ALWAYS,
        gst_caps_from_string (VIDEO_SRC_CAPS)));
  gst_element_class_add_pad_template (GST_ELEMENT_CLASS(klass),
      gst_pad_template_new ("sink", GST_PAD_SINK, GST_PAD_ALWAYS,
        gst_caps_from_string (VIDEO_SINK_CAPS)));

  gst_element_class_set_static_metadata (GST_ELEMENT_CLASS(klass),
      "FIXME Long name", "Generic", "FIXME Description",
      "FIXME <fixme@example.com>");

  gobject_class->set_property = gst_rkbboxdraw_set_property;
  gobject_class->get_property = gst_rkbboxdraw_get_property;
  gobject_class->dispose = gst_rkbboxdraw_dispose;
  gobject_class->finalize = gst_rkbboxdraw_finalize;
  base_transform_class->start = GST_DEBUG_FUNCPTR (gst_rkbboxdraw_start);
  base_transform_class->stop = GST_DEBUG_FUNCPTR (gst_rkbboxdraw_stop);
  video_filter_class->set_info = GST_DEBUG_FUNCPTR (gst_rkbboxdraw_set_info);
  // video_filter_class->transform_frame = GST_DEBUG_FUNCPTR (gst_rkbboxdraw_transform_frame);
  video_filter_class->transform_frame_ip = GST_DEBUG_FUNCPTR (gst_rkbboxdraw_transform_frame_ip);

}

static void
gst_rkbboxdraw_init (GstRkbboxdraw *rkbboxdraw)
{
}

void
gst_rkbboxdraw_set_property (GObject * object, guint property_id,
    const GValue * value, GParamSpec * pspec)
{
  GstRkbboxdraw *rkbboxdraw = GST_RKBBOXDRAW (object);

  GST_DEBUG_OBJECT (rkbboxdraw, "set_property");

  switch (property_id) {
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
      break;
  }
}

void
gst_rkbboxdraw_get_property (GObject * object, guint property_id,
    GValue * value, GParamSpec * pspec)
{
  GstRkbboxdraw *rkbboxdraw = GST_RKBBOXDRAW (object);

  GST_DEBUG_OBJECT (rkbboxdraw, "get_property");

  switch (property_id) {
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
      break;
  }
}

void
gst_rkbboxdraw_dispose (GObject * object)
{
  GstRkbboxdraw *rkbboxdraw = GST_RKBBOXDRAW (object);

  GST_DEBUG_OBJECT (rkbboxdraw, "dispose");

  /* clean up as possible.  may be called multiple times */

  G_OBJECT_CLASS (gst_rkbboxdraw_parent_class)->dispose (object);
}

void
gst_rkbboxdraw_finalize (GObject * object)
{
  GstRkbboxdraw *rkbboxdraw = GST_RKBBOXDRAW (object);

  GST_DEBUG_OBJECT (rkbboxdraw, "finalize");

  /* clean up object here */

  G_OBJECT_CLASS (gst_rkbboxdraw_parent_class)->finalize (object);
}

static gboolean
gst_rkbboxdraw_start (GstBaseTransform * trans)
{
  GstRkbboxdraw *rkbboxdraw = GST_RKBBOXDRAW (trans);

  GST_DEBUG_OBJECT (rkbboxdraw, "start");

  return TRUE;
}

static gboolean
gst_rkbboxdraw_stop (GstBaseTransform * trans)
{
  GstRkbboxdraw *rkbboxdraw = GST_RKBBOXDRAW (trans);

  GST_DEBUG_OBJECT (rkbboxdraw, "stop");

  return TRUE;
}

static gboolean
gst_rkbboxdraw_set_info (GstVideoFilter * filter, GstCaps * incaps,
    GstVideoInfo * in_info, GstCaps * outcaps, GstVideoInfo * out_info)
{
  GstRkbboxdraw *rkbboxdraw = GST_RKBBOXDRAW (filter);

  GST_DEBUG_OBJECT (rkbboxdraw, "set_info");

  return TRUE;
}

/* transform */
static GstFlowReturn
gst_rkbboxdraw_transform_frame (GstVideoFilter * filter, GstVideoFrame * inframe,
    GstVideoFrame * outframe)
{
  GstRkbboxdraw *rkbboxdraw = GST_RKBBOXDRAW (filter);

  GST_DEBUG_OBJECT (rkbboxdraw, "transform_frame");

  return GST_FLOW_OK;
}

static GstFlowReturn
gst_rkbboxdraw_transform_frame_ip (GstVideoFilter * filter, GstVideoFrame * frame)
{
  GstRkbboxdraw *rkbboxdraw = GST_RKBBOXDRAW (filter);

  GST_DEBUG_OBJECT (rkbboxdraw, "transform_frame_ip");

  /* IMAGE PROCESSING CODE BLOCK BEGIN */
  // Meta data
  GstBufferInfoMeta* gst_buffer_info_meta = (GstBufferInfoMeta *) gst_buffer_get_meta((frame->buffer), GST_BUFFER_INFO_META_API_TYPE);

  if (gst_buffer_info_meta == NULL) {
    // Do not have bbox to draw
    return GST_FLOW_OK;
  }

  auto detector_start = std::chrono::steady_clock::now();

  cv::Mat img(GST_VIDEO_FRAME_HEIGHT(frame), GST_VIDEO_FRAME_WIDTH(frame), CV_8UC3, GST_VIDEO_FRAME_PLANE_DATA(frame, 0));

  for (size_t face_num = 0; face_num < gst_buffer_info_meta->num_boxes; face_num++) {
    cv::Point pt1(gst_buffer_info_meta->boxes[face_num].x, gst_buffer_info_meta->boxes[face_num].y);
    cv::Point pt2(gst_buffer_info_meta->boxes[face_num].x + gst_buffer_info_meta->boxes[face_num].width,
                  gst_buffer_info_meta->boxes[face_num].y + gst_buffer_info_meta->boxes[face_num].height);
    cv::rectangle(img, pt1, pt2, cv::Scalar(0, 255, 0), 2);
  }

  auto detector_end = std::chrono::steady_clock::now();

  img.release();
  /* IMAGE PROCESSING CODE BLOCK END */
  std::chrono::duration<double> detect_time = detector_end - detector_start;
  std::cout << "bbox_time: " << detect_time.count() << " s" << std::endl;
  return GST_FLOW_OK;
}

static gboolean
plugin_init (GstPlugin * plugin)
{

  /* FIXME Remember to set the rank if it's an element that is meant
     to be autoplugged by decodebin. */
  return gst_element_register (plugin, "rkbboxdraw", GST_RANK_NONE,
      GST_TYPE_RKBBOXDRAW);
}

/* FIXME: these are normally defined by the GStreamer build system.
   If you are creating an element to be included in gst-plugins-*,
   remove these, as they're always defined.  Otherwise, edit as
   appropriate for your external plugin package. */
#ifndef VERSION
#define VERSION "0.0.FIXME"
#endif
#ifndef PACKAGE
#define PACKAGE "FIXME_package"
#endif
#ifndef PACKAGE_NAME
#define PACKAGE_NAME "FIXME_package_name"
#endif
#ifndef GST_PACKAGE_ORIGIN
#define GST_PACKAGE_ORIGIN "http://FIXME.org/"
#endif

GST_PLUGIN_DEFINE (GST_VERSION_MAJOR,
    GST_VERSION_MINOR,
    rkbboxdraw,
    "FIXME plugin description",
    plugin_init, VERSION, "LGPL", PACKAGE_NAME, GST_PACKAGE_ORIGIN)
