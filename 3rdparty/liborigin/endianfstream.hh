/***************************************************************************
	File                 : endianfstream.hh
	--------------------------------------------------------------------
	Copyright            : (C) 2008 Alex Kargovsky
						   Email (use @ for *)  : kargovsky*yumr.phys.msu.su
	Description          : Endianless file stream class

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *  This program is free software; you can redistribute it and/or modify   *
 *  it under the terms of the GNU General Public License as published by   *
 *  the Free Software Foundation; either version 2 of the License, or      *
 *  (at your option) any later version.                                    *
 *                                                                         *
 *  This program is distributed in the hope that it will be useful,        *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *  GNU General Public License for more details.                           *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the Free Software           *
 *   Foundation, Inc., 51 Franklin Street, Fifth Floor,                    *
 *   Boston, MA  02110-1301  USA                                           *
 *                                                                         *
 ***************************************************************************/

#ifndef ENDIAN_FSTREAM_H
#define ENDIAN_FSTREAM_H

#include <fstream>

namespace std
{
	class iendianfstream : public ifstream
	{
	public:
		iendianfstream(const char *_Filename, ios_base::openmode _Mode = ios_base::in)
			:	ifstream(_Filename, _Mode)
		{
			short word = 0x4321;
			bigEndian = (*(char*)& word) != 0x21;
		};

		iendianfstream& operator>>(bool& value)
		{
			read(reinterpret_cast<char*>(&value), sizeof(value));
			return *this;
		}

		iendianfstream& operator>>(char& value)
		{
			get(value);
			return *this;
		}

		iendianfstream& operator>>(unsigned char& value)
		{
			get(reinterpret_cast<char&>(value));
			return *this;
		}

		iendianfstream& operator>>(short& value)
		{
			read(reinterpret_cast<char*>(&value), sizeof(value));
			if(bigEndian)
				swapBytes(reinterpret_cast<unsigned char*>(&value), sizeof(value));

			return *this;
		}

		iendianfstream& operator>>(unsigned short& value)
		{
			read(reinterpret_cast<char*>(&value), sizeof(value));
			if(bigEndian)
				swapBytes(reinterpret_cast<unsigned char*>(&value), sizeof(value));

			return *this;
		}

		iendianfstream& operator>>(int& value)
		{
			read(reinterpret_cast<char*>(&value), sizeof(value));
			if(bigEndian)
				swapBytes(reinterpret_cast<unsigned char*>(&value), sizeof(value));

			return *this;
		}

		iendianfstream& operator>>(unsigned int& value)
		{
			read(reinterpret_cast<char*>(&value), sizeof(value));
			if(bigEndian)
				swapBytes(reinterpret_cast<unsigned char*>(&value), sizeof(value));

			return *this;
		}

		iendianfstream& operator>>(long& value)
		{
			read(reinterpret_cast<char*>(&value), sizeof(value));
			if(bigEndian)
				swapBytes(reinterpret_cast<unsigned char*>(&value), sizeof(value));

			return *this;
		}

		iendianfstream& operator>>(unsigned long& value)
		{
			read(reinterpret_cast<char*>(&value), sizeof(value));
			if(bigEndian)
				swapBytes(reinterpret_cast<unsigned char*>(&value), sizeof(value));

			return *this;
		}

		iendianfstream& operator>>(float& value)
		{
			read(reinterpret_cast<char*>(&value), sizeof(value));
			if(bigEndian)
				swapBytes(reinterpret_cast<unsigned char*>(&value), sizeof(value));

			return *this;
		}

		iendianfstream& operator>>(double& value)
		{
			read(reinterpret_cast<char*>(&value), sizeof(value));
			if(bigEndian)
				swapBytes(reinterpret_cast<unsigned char*>(&value), sizeof(value));

			return *this;
		}

		iendianfstream& operator>>(long double& value)
		{
			read(reinterpret_cast<char*>(&value), sizeof(value));
			if(bigEndian)
				swapBytes(reinterpret_cast<unsigned char*>(&value), sizeof(value));

			return *this;
		}

	private:
		bool bigEndian;
		void swapBytes(unsigned char* data, int size)
		{
			register int i = 0;
			register int j = size - 1;
			while(i < j)
			{
				std::swap(data[i], data[j]);
				++i, --j;
			}
		}
	};
}

#endif // ENDIAN_FSTREAM_H