/**
 * Orthanc - A Lightweight, RESTful DICOM Store
 * Copyright (C) 2012-2016 Sebastien Jodogne, Medical Physics
 * Department, University Hospital of Liege, Belgium
 * Copyright (C) 2017-2021 Osimis S.A., Belgium
 *
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program. If not, see
 * <http://www.gnu.org/licenses/>.
 **/


#pragma once

#include "IDicomTranscoder.h"

namespace Orthanc
{
  // This is the basis class for transcoding plugins
  class MemoryBufferTranscoder : public IDicomTranscoder
  {
  protected:
    virtual bool TranscodeBuffer(std::string& target,
                                 const void* buffer,
                                 size_t size,
                                 const std::set<DicomTransferSyntax>& allowedSyntaxes,
                                 bool allowNewSopInstanceUid) = 0;
    
  public:
    virtual bool Transcode(DicomImage& target /* out */,
                           DicomImage& source,
                           const std::set<DicomTransferSyntax>& allowedSyntaxes,
                           bool allowNewSopInstanceUid) ORTHANC_OVERRIDE;
  };
}
