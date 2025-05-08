/**
 * @file kernel.hpp
 * @brief Header file for the Kernel class.
 *
 * This file contains the declaration of the Kernel class, which is part of the
 * `kernel` namespace. The Kernel class provides the basic structure for kernel
 * operations.
 *
 * @copyright Copyright (c) 2025 Clément Antoine XAVIER
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#pragma once

namespace kernel {

/**
 * @class kernel::Kernel
 * @brief Represents the core kernel functionality.
 *
 * The Kernel class provides the basic structure for initializing and
 * managing kernel operations. It includes a constructor and a destructor
 * for resource management.
 */
class Kernel {
public:
  /**
   * @brief Default constructor for the Kernel class.
   *
   * Initializes the kernel instance.
   */
  Kernel(void);

  /**
   * @brief Destructor for the Kernel class.
   *
   * Cleans up resources used by the kernel instance.
   */
  ~Kernel(void);
};

} // namespace kernel
