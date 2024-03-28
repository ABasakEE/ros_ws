// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tutorial_interfaces:srv/CVImg.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__SRV__DETAIL__CV_IMG__BUILDER_HPP_
#define TUTORIAL_INTERFACES__SRV__DETAIL__CV_IMG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tutorial_interfaces/srv/detail/cv_img__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tutorial_interfaces
{

namespace srv
{

namespace builder
{

class Init_CVImg_Request_img
{
public:
  Init_CVImg_Request_img()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tutorial_interfaces::srv::CVImg_Request img(::tutorial_interfaces::srv::CVImg_Request::_img_type arg)
  {
    msg_.img = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::srv::CVImg_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::srv::CVImg_Request>()
{
  return tutorial_interfaces::srv::builder::Init_CVImg_Request_img();
}

}  // namespace tutorial_interfaces


namespace tutorial_interfaces
{

namespace srv
{

namespace builder
{

class Init_CVImg_Response_corners
{
public:
  explicit Init_CVImg_Response_corners(::tutorial_interfaces::srv::CVImg_Response & msg)
  : msg_(msg)
  {}
  ::tutorial_interfaces::srv::CVImg_Response corners(::tutorial_interfaces::srv::CVImg_Response::_corners_type arg)
  {
    msg_.corners = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::srv::CVImg_Response msg_;
};

class Init_CVImg_Response_ids
{
public:
  explicit Init_CVImg_Response_ids(::tutorial_interfaces::srv::CVImg_Response & msg)
  : msg_(msg)
  {}
  Init_CVImg_Response_corners ids(::tutorial_interfaces::srv::CVImg_Response::_ids_type arg)
  {
    msg_.ids = std::move(arg);
    return Init_CVImg_Response_corners(msg_);
  }

private:
  ::tutorial_interfaces::srv::CVImg_Response msg_;
};

class Init_CVImg_Response_step
{
public:
  Init_CVImg_Response_step()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CVImg_Response_ids step(::tutorial_interfaces::srv::CVImg_Response::_step_type arg)
  {
    msg_.step = std::move(arg);
    return Init_CVImg_Response_ids(msg_);
  }

private:
  ::tutorial_interfaces::srv::CVImg_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::srv::CVImg_Response>()
{
  return tutorial_interfaces::srv::builder::Init_CVImg_Response_step();
}

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__SRV__DETAIL__CV_IMG__BUILDER_HPP_
