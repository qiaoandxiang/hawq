/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#ifndef STORAGE_SRC_STORAGE_FORMAT_ORC_DATA_BUFFER_H_
#define STORAGE_SRC_STORAGE_FORMAT_ORC_DATA_BUFFER_H_

#include <memory>

#include "dbcommon/utils/memory-pool.h"

namespace orc {

template <class T>
class DataBuffer {
 private:
  dbcommon::MemoryPool& memoryPool;
  T* buf;
  // current size
  uint64_t currentSize;
  // maximal capacity (actual allocated memory)
  uint64_t currentCapacity;

  // not implemented
  DataBuffer(DataBuffer& buffer);             // NOLINT
  DataBuffer& operator=(DataBuffer& buffer);  // NOLINT

 public:
  explicit DataBuffer(dbcommon::MemoryPool& pool,  // NOLINT
                      uint64_t _size = 0);
  virtual ~DataBuffer();

  T* data() { return buf; }

  const T* data() const { return buf; }

  uint64_t size() { return currentSize; }

  uint64_t capacity() { return currentCapacity; }

  T& operator[](uint64_t i) { return buf[i]; }

  void resize(uint64_t _size);
};

}  // namespace orc
#endif  // STORAGE_SRC_STORAGE_FORMAT_ORC_DATA_BUFFER_H_
