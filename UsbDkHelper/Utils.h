/**********************************************************************
* Copyright (c) 2013-2014  Red Hat, Inc.
*
* Developed by Daynix Computing LTD.
*
* Authors:
*     Dmitry Fleytman <dmitry@daynix.com>
*     Pavel Gurvich <pavel@daynix.com>
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
**********************************************************************/

#pragma once

template <typename HandleT>
class UsbDkHandleHolder
{
public:
    UsbDkHandleHolder(HandleT Handle)
        : m_Handle(Handle)
    {}

    ~UsbDkHandleHolder()
    {
        if (m_Handle != nullptr)
        {
            Close();
        }
    }

    operator bool() const { return m_Handle != nullptr; }
    operator HandleT() const { return m_Handle; }

private:
    void Close();
    HandleT m_Handle;
};
