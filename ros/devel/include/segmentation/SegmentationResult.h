// Generated by gencpp from file segmentation/SegmentationResult.msg
// DO NOT EDIT!


#ifndef SEGMENTATION_MESSAGE_SEGMENTATIONRESULT_H
#define SEGMENTATION_MESSAGE_SEGMENTATIONRESULT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <sensor_msgs/Image.h>

namespace segmentation
{
template <class ContainerAllocator>
struct SegmentationResult_
{
  typedef SegmentationResult_<ContainerAllocator> Type;

  SegmentationResult_()
    : height(0)
    , width(0)
    , depth(0)
    , data()  {
    }
  SegmentationResult_(const ContainerAllocator& _alloc)
    : height(0)
    , width(0)
    , depth(0)
    , data(_alloc)  {
  (void)_alloc;
    }



   typedef uint32_t _height_type;
  _height_type height;

   typedef uint32_t _width_type;
  _width_type width;

   typedef uint32_t _depth_type;
  _depth_type depth;

   typedef std::vector< ::sensor_msgs::Image_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::sensor_msgs::Image_<ContainerAllocator> >::other >  _data_type;
  _data_type data;





  typedef boost::shared_ptr< ::segmentation::SegmentationResult_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::segmentation::SegmentationResult_<ContainerAllocator> const> ConstPtr;

}; // struct SegmentationResult_

typedef ::segmentation::SegmentationResult_<std::allocator<void> > SegmentationResult;

typedef boost::shared_ptr< ::segmentation::SegmentationResult > SegmentationResultPtr;
typedef boost::shared_ptr< ::segmentation::SegmentationResult const> SegmentationResultConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::segmentation::SegmentationResult_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::segmentation::SegmentationResult_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace segmentation

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'sensor_msgs': ['/opt/ros/melodic/share/sensor_msgs/cmake/../msg'], 'segmentation': ['/home/neil/Workspace/self-driving-golf-cart/ros/src/segmentation/msg'], 'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/melodic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::segmentation::SegmentationResult_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::segmentation::SegmentationResult_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::segmentation::SegmentationResult_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::segmentation::SegmentationResult_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::segmentation::SegmentationResult_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::segmentation::SegmentationResult_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::segmentation::SegmentationResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "5052522eddaa15fba41aac6bebabe984";
  }

  static const char* value(const ::segmentation::SegmentationResult_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x5052522eddaa15fbULL;
  static const uint64_t static_value2 = 0xa41aac6bebabe984ULL;
};

template<class ContainerAllocator>
struct DataType< ::segmentation::SegmentationResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "segmentation/SegmentationResult";
  }

  static const char* value(const ::segmentation::SegmentationResult_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::segmentation::SegmentationResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint32 height\n\
uint32 width\n\
uint32 depth\n\
sensor_msgs/Image[] data\n\
================================================================================\n\
MSG: sensor_msgs/Image\n\
# This message contains an uncompressed image\n\
# (0, 0) is at top-left corner of image\n\
#\n\
\n\
Header header        # Header timestamp should be acquisition time of image\n\
                     # Header frame_id should be optical frame of camera\n\
                     # origin of frame should be optical center of cameara\n\
                     # +x should point to the right in the image\n\
                     # +y should point down in the image\n\
                     # +z should point into to plane of the image\n\
                     # If the frame_id here and the frame_id of the CameraInfo\n\
                     # message associated with the image conflict\n\
                     # the behavior is undefined\n\
\n\
uint32 height         # image height, that is, number of rows\n\
uint32 width          # image width, that is, number of columns\n\
\n\
# The legal values for encoding are in file src/image_encodings.cpp\n\
# If you want to standardize a new string format, join\n\
# ros-users@lists.sourceforge.net and send an email proposing a new encoding.\n\
\n\
string encoding       # Encoding of pixels -- channel meaning, ordering, size\n\
                      # taken from the list of strings in include/sensor_msgs/image_encodings.h\n\
\n\
uint8 is_bigendian    # is this data bigendian?\n\
uint32 step           # Full row length in bytes\n\
uint8[] data          # actual matrix data, size is (step * rows)\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::segmentation::SegmentationResult_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::segmentation::SegmentationResult_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.height);
      stream.next(m.width);
      stream.next(m.depth);
      stream.next(m.data);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SegmentationResult_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::segmentation::SegmentationResult_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::segmentation::SegmentationResult_<ContainerAllocator>& v)
  {
    s << indent << "height: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.height);
    s << indent << "width: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.width);
    s << indent << "depth: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.depth);
    s << indent << "data[]" << std::endl;
    for (size_t i = 0; i < v.data.size(); ++i)
    {
      s << indent << "  data[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::sensor_msgs::Image_<ContainerAllocator> >::stream(s, indent + "    ", v.data[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // SEGMENTATION_MESSAGE_SEGMENTATIONRESULT_H
