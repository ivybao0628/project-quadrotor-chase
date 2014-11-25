/*******************************************************************************
 * Copyright (c) 2009-2014, MAV'RIC Development Team
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice, 
 * this list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright notice, 
 * this list of conditions and the following disclaimer in the documentation 
 * and/or other materials provided with the distribution.
 * 
 * 3. Neither the name of the copyright holder nor the names of its contributors
 * may be used to endorse or promote products derived from this software without
 * specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/

/*******************************************************************************
 * \file bmp085_telemetry.c
 * 
 * \author MAV'RIC Team
 * \author Nicolas Dousse
 *   
 * \brief This module takes care of sending periodic telemetric messages for
 * the pressure sensor
 *
 ******************************************************************************/


#include "bmp085_telemetry.h"
#include "time_keeper.h"


void bmp085_telemetry_send_pressure(const barometer_t* bmp085, const mavlink_stream_t* mavlink_stream, mavlink_message_t* msg)
{
	mavlink_msg_scaled_pressure_pack(	mavlink_stream->sysid,
										mavlink_stream->compid,
										msg,
										time_keeper_get_millis(),
										bmp085->pressure / 100.0f,
										bmp085->vario_vz,
										bmp085->temperature * 100.0f);

	// mavlink_msg_named_value_float_pack(	bmp085->mavlink_stream->sysid,
	// 									bmp085->mavlink_stream->compid,
	// 									&msg,
	// 									time_keeper_get_millis(),
	// 									"pressAlt",
	// 									bmp085->altitude);

	// mavlink_stream_send(bmp085->mavlink_stream,&msg);

}