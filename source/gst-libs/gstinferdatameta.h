#ifndef __GST_BUFFER_INFO_META_H__
#define __GST_BUFFER_INFO_META_H__
 
#include <gst/gst.h>
 
 
G_BEGIN_DECLS
 
typedef enum {
    GST_BUFFER_INFO_META_PARTIAL_RELIABILITY_NONE,
    GST_BUFFER_INFO_META_PARTIAL_RELIABILITY_TTL,
    GST_BUFFER_INFO_META_PARTIAL_RELIABILITY_BUF,
    GST_BUFFER_INFO_META_PARTIAL_RELIABILITY_RTX 
} GstBufferInfoMetaPartiallyReliability;
 
#define GST_BUFFER_INFO_META_API_TYPE (gst_buffer_info_meta_api_get_type())
#define GST_BUFFER_INFO_META_INFO     (gst_buffer_info_meta_get_info())

#define FACE_VECTOR_LENGTH 512
 
typedef struct _GstBufferInfoMeta  GstBufferInfoMeta;
typedef struct _GstBufferInfo      GstBufferInfo    ;

struct _GstBufferInfo {
    gchar label;
    gfloat x;
    gfloat y;
    gfloat width;
    gfloat height;
    gfloat embedding[FACE_VECTOR_LENGTH];
};

struct _GstBufferInfoMeta {
    GstMeta meta;
    gint num_boxes;
    GstBufferInfo *boxes;
};  


GType gst_buffer_info_meta_api_get_type(void);
 
GST_EXPORT
const GstMetaInfo * gst_buffer_info_meta_get_info(void);
 
GST_EXPORT
GstBufferInfoMeta* gst_buffer_add_buffer_info_meta(GstBuffer *buffer, GstBufferInfo*);

GST_EXPORT
gboolean gst_buffer_remove_buffer_info_meta(GstBuffer *buffer);

GST_EXPORT 
GstBufferInfo* gst_buffer_get_buffer_info_meta(GstBuffer* b);
 
G_END_DECLS
 
#endif /* __GST_BUFFER_INFO_META_H__ */