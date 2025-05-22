/// @file
/// @copyright © 2022 Oktal Sydac
/// This is unpublished proprietary source code. The copyright notice above
/// does not evidence any actual or intended publication of such source code.
#pragma once
#include <utility>

/// Returns a lambda that is bound to an object member function.
template <typename ReturnType, class Class, typename... Args>
auto CreateCallback(ReturnType (Class::*member_function)(Args...), Class *object_ptr)
{
    return
      [object_ptr, member_function](Args&&... args)
      {
          return (object_ptr->*member_function)(std::forward<Args>(args)...);
      };
}
