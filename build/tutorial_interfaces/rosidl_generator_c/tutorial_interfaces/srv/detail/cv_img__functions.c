// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tutorial_interfaces:srv/CVImg.idl
// generated code does not contain a copyright notice
#include "tutorial_interfaces/srv/detail/cv_img__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `img`
#include "sensor_msgs/msg/detail/image__functions.h"

bool
tutorial_interfaces__srv__CVImg_Request__init(tutorial_interfaces__srv__CVImg_Request * msg)
{
  if (!msg) {
    return false;
  }
  // img
  if (!sensor_msgs__msg__Image__init(&msg->img)) {
    tutorial_interfaces__srv__CVImg_Request__fini(msg);
    return false;
  }
  return true;
}

void
tutorial_interfaces__srv__CVImg_Request__fini(tutorial_interfaces__srv__CVImg_Request * msg)
{
  if (!msg) {
    return;
  }
  // img
  sensor_msgs__msg__Image__fini(&msg->img);
}

bool
tutorial_interfaces__srv__CVImg_Request__are_equal(const tutorial_interfaces__srv__CVImg_Request * lhs, const tutorial_interfaces__srv__CVImg_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // img
  if (!sensor_msgs__msg__Image__are_equal(
      &(lhs->img), &(rhs->img)))
  {
    return false;
  }
  return true;
}

bool
tutorial_interfaces__srv__CVImg_Request__copy(
  const tutorial_interfaces__srv__CVImg_Request * input,
  tutorial_interfaces__srv__CVImg_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // img
  if (!sensor_msgs__msg__Image__copy(
      &(input->img), &(output->img)))
  {
    return false;
  }
  return true;
}

tutorial_interfaces__srv__CVImg_Request *
tutorial_interfaces__srv__CVImg_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__srv__CVImg_Request * msg = (tutorial_interfaces__srv__CVImg_Request *)allocator.allocate(sizeof(tutorial_interfaces__srv__CVImg_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tutorial_interfaces__srv__CVImg_Request));
  bool success = tutorial_interfaces__srv__CVImg_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tutorial_interfaces__srv__CVImg_Request__destroy(tutorial_interfaces__srv__CVImg_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tutorial_interfaces__srv__CVImg_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tutorial_interfaces__srv__CVImg_Request__Sequence__init(tutorial_interfaces__srv__CVImg_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__srv__CVImg_Request * data = NULL;

  if (size) {
    data = (tutorial_interfaces__srv__CVImg_Request *)allocator.zero_allocate(size, sizeof(tutorial_interfaces__srv__CVImg_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tutorial_interfaces__srv__CVImg_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tutorial_interfaces__srv__CVImg_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
tutorial_interfaces__srv__CVImg_Request__Sequence__fini(tutorial_interfaces__srv__CVImg_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      tutorial_interfaces__srv__CVImg_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

tutorial_interfaces__srv__CVImg_Request__Sequence *
tutorial_interfaces__srv__CVImg_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__srv__CVImg_Request__Sequence * array = (tutorial_interfaces__srv__CVImg_Request__Sequence *)allocator.allocate(sizeof(tutorial_interfaces__srv__CVImg_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tutorial_interfaces__srv__CVImg_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tutorial_interfaces__srv__CVImg_Request__Sequence__destroy(tutorial_interfaces__srv__CVImg_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tutorial_interfaces__srv__CVImg_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tutorial_interfaces__srv__CVImg_Request__Sequence__are_equal(const tutorial_interfaces__srv__CVImg_Request__Sequence * lhs, const tutorial_interfaces__srv__CVImg_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tutorial_interfaces__srv__CVImg_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tutorial_interfaces__srv__CVImg_Request__Sequence__copy(
  const tutorial_interfaces__srv__CVImg_Request__Sequence * input,
  tutorial_interfaces__srv__CVImg_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tutorial_interfaces__srv__CVImg_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tutorial_interfaces__srv__CVImg_Request * data =
      (tutorial_interfaces__srv__CVImg_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tutorial_interfaces__srv__CVImg_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tutorial_interfaces__srv__CVImg_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tutorial_interfaces__srv__CVImg_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `ids`
// Member `corners`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
tutorial_interfaces__srv__CVImg_Response__init(tutorial_interfaces__srv__CVImg_Response * msg)
{
  if (!msg) {
    return false;
  }
  // step
  // ids
  if (!rosidl_runtime_c__float__Sequence__init(&msg->ids, 0)) {
    tutorial_interfaces__srv__CVImg_Response__fini(msg);
    return false;
  }
  // corners
  if (!rosidl_runtime_c__float__Sequence__init(&msg->corners, 0)) {
    tutorial_interfaces__srv__CVImg_Response__fini(msg);
    return false;
  }
  return true;
}

void
tutorial_interfaces__srv__CVImg_Response__fini(tutorial_interfaces__srv__CVImg_Response * msg)
{
  if (!msg) {
    return;
  }
  // step
  // ids
  rosidl_runtime_c__float__Sequence__fini(&msg->ids);
  // corners
  rosidl_runtime_c__float__Sequence__fini(&msg->corners);
}

bool
tutorial_interfaces__srv__CVImg_Response__are_equal(const tutorial_interfaces__srv__CVImg_Response * lhs, const tutorial_interfaces__srv__CVImg_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // step
  if (lhs->step != rhs->step) {
    return false;
  }
  // ids
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->ids), &(rhs->ids)))
  {
    return false;
  }
  // corners
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->corners), &(rhs->corners)))
  {
    return false;
  }
  return true;
}

bool
tutorial_interfaces__srv__CVImg_Response__copy(
  const tutorial_interfaces__srv__CVImg_Response * input,
  tutorial_interfaces__srv__CVImg_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // step
  output->step = input->step;
  // ids
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->ids), &(output->ids)))
  {
    return false;
  }
  // corners
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->corners), &(output->corners)))
  {
    return false;
  }
  return true;
}

tutorial_interfaces__srv__CVImg_Response *
tutorial_interfaces__srv__CVImg_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__srv__CVImg_Response * msg = (tutorial_interfaces__srv__CVImg_Response *)allocator.allocate(sizeof(tutorial_interfaces__srv__CVImg_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tutorial_interfaces__srv__CVImg_Response));
  bool success = tutorial_interfaces__srv__CVImg_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tutorial_interfaces__srv__CVImg_Response__destroy(tutorial_interfaces__srv__CVImg_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tutorial_interfaces__srv__CVImg_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tutorial_interfaces__srv__CVImg_Response__Sequence__init(tutorial_interfaces__srv__CVImg_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__srv__CVImg_Response * data = NULL;

  if (size) {
    data = (tutorial_interfaces__srv__CVImg_Response *)allocator.zero_allocate(size, sizeof(tutorial_interfaces__srv__CVImg_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tutorial_interfaces__srv__CVImg_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tutorial_interfaces__srv__CVImg_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
tutorial_interfaces__srv__CVImg_Response__Sequence__fini(tutorial_interfaces__srv__CVImg_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      tutorial_interfaces__srv__CVImg_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

tutorial_interfaces__srv__CVImg_Response__Sequence *
tutorial_interfaces__srv__CVImg_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tutorial_interfaces__srv__CVImg_Response__Sequence * array = (tutorial_interfaces__srv__CVImg_Response__Sequence *)allocator.allocate(sizeof(tutorial_interfaces__srv__CVImg_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tutorial_interfaces__srv__CVImg_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tutorial_interfaces__srv__CVImg_Response__Sequence__destroy(tutorial_interfaces__srv__CVImg_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tutorial_interfaces__srv__CVImg_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tutorial_interfaces__srv__CVImg_Response__Sequence__are_equal(const tutorial_interfaces__srv__CVImg_Response__Sequence * lhs, const tutorial_interfaces__srv__CVImg_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tutorial_interfaces__srv__CVImg_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tutorial_interfaces__srv__CVImg_Response__Sequence__copy(
  const tutorial_interfaces__srv__CVImg_Response__Sequence * input,
  tutorial_interfaces__srv__CVImg_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tutorial_interfaces__srv__CVImg_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tutorial_interfaces__srv__CVImg_Response * data =
      (tutorial_interfaces__srv__CVImg_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tutorial_interfaces__srv__CVImg_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tutorial_interfaces__srv__CVImg_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tutorial_interfaces__srv__CVImg_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
