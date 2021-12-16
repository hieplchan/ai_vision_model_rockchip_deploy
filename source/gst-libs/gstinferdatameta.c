#include "gstinferdatameta.h"

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

static gboolean gst_buffer_info_meta_init(GstMeta *meta, gpointer params, GstBuffer *buffer);
static void gst_buffer_info_meta_free (GstMeta * meta, GstBuffer * buffer);
static gboolean gst_buffer_info_meta_transform(GstBuffer *transbuf, GstMeta *meta, GstBuffer *buffer,
                                               GQuark type, gpointer data);


GType gst_buffer_info_meta_api_get_type(void)
{
    static const gchar *tags[] = {NULL};
    static volatile GType type;
    if (g_once_init_enter (&type)) {
        GType _type = gst_meta_api_type_register("GstBufferInfoMetaAPI", tags);
        g_once_init_leave(&type, _type);
    }
    return type;
}

const GstMetaInfo *gst_buffer_info_meta_get_info(void)
{
    static const GstMetaInfo *gst_buffer_info_meta_info = NULL;
 
    if (g_once_init_enter (&gst_buffer_info_meta_info)) {
        const GstMetaInfo *meta = gst_meta_register (GST_BUFFER_INFO_META_API_TYPE, /* api type */
                                                     "GstBufferInfoMeta",           /* implementation type */
                                                     sizeof (GstBufferInfoMeta),    /* size of the structure */
                                                     gst_buffer_info_meta_init,
                                                     gst_buffer_info_meta_free,
                                                     gst_buffer_info_meta_transform);
        g_once_init_leave (&gst_buffer_info_meta_info, meta);
    }
    return gst_buffer_info_meta_info;
}
 
static gboolean gst_buffer_info_meta_init(GstMeta *meta, gpointer params, GstBuffer *buffer)
{
    GstBufferInfoMeta *gst_buffer_info_meta = (GstBufferInfoMeta *) meta;     
    gst_buffer_info_meta->boxes = NULL;
    gst_buffer_info_meta->num_boxes = 0;
    return TRUE;
}

static void gst_buffer_info_meta_free (GstMeta * meta, GstBuffer * buffer)
{
  GstBufferInfoMeta *gst_buffer_info_meta = (GstBufferInfoMeta *) meta;

  g_return_if_fail (meta != NULL);
  g_return_if_fail (buffer != NULL);

  if (gst_buffer_info_meta->num_boxes != 0) {
    g_free (gst_buffer_info_meta->boxes);
  }
}

static gboolean gst_buffer_info_meta_copy (GstBuffer * dest, GstMeta * meta, GstBuffer * buffer)
{
  GstBufferInfoMeta *dmeta, *smeta;
  gsize raw_size;

  g_return_val_if_fail (dest, FALSE);
  g_return_val_if_fail (meta, FALSE);
  g_return_val_if_fail (buffer, FALSE);

  smeta = (GstBufferInfoMeta *) meta;
  dmeta = (GstBufferInfoMeta *) gst_buffer_add_meta (dest, GST_BUFFER_INFO_META_INFO, NULL);
  if (!dmeta) {
    GST_ERROR ("Unable to add meta to buffer");
    return FALSE;
  }

  dmeta->num_boxes = smeta->num_boxes;
  raw_size = dmeta->num_boxes * sizeof (GstBufferInfo);
  dmeta->boxes = (GstBufferInfo *) g_malloc (raw_size);
  memcpy (dmeta->boxes, smeta->boxes, raw_size);

  return TRUE;
}


static gboolean gst_buffer_info_meta_transform(GstBuffer *transbuf, GstMeta *meta, GstBuffer *buffer,
                                               GQuark type, gpointer data)
{
    if (GST_META_TRANSFORM_IS_COPY (type)) {
        GST_LOG ("Copy metadata");
        return gst_buffer_info_meta_copy (transbuf, meta, buffer);
    }

    /* No transform supported */
    return FALSE;
}

gboolean gst_buffer_remove_buffer_info_meta(GstBuffer *buffer)
{
    g_return_val_if_fail(GST_IS_BUFFER(buffer), FALSE);

    GstBufferInfoMeta* meta = (GstBufferInfoMeta*)gst_buffer_get_meta((buffer), GST_BUFFER_INFO_META_API_TYPE);

    if (meta == NULL)
        return TRUE;
    
    if ( !gst_buffer_is_writable(buffer))
        return FALSE;

    return gst_buffer_remove_meta(buffer, &meta->meta);
}