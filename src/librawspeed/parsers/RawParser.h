/*
    RawSpeed - RAW file decoder.

    Copyright (C) 2009-2014 Klaus Post

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/

#pragma once

#include <memory> // for unique_ptr

namespace rawspeed {

class Buffer;

class CameraMetaData;

class RawDecoder;

class RawParser {
public:
  explicit RawParser(const Buffer& inputData) : mInput(inputData) {}
  virtual ~RawParser() = default;

  virtual std::unique_ptr<RawDecoder>
  getDecoder(const CameraMetaData* meta = nullptr);

protected:
  const Buffer& mInput;
};

} // namespace rawspeed
