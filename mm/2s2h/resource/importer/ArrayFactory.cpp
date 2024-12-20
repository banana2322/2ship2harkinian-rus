#include "2s2h/resource/importer/ArrayFactory.h"
#include "2s2h/resource/type/Array.h"
#include "spdlog/spdlog.h"
#include "graphic/Fast3D/lus_gbi.h"

namespace SOH {
std::shared_ptr<Ship::IResource> ResourceFactoryBinaryArrayV0::ReadResource(std::shared_ptr<Ship::File> file) {
    if (!FileHasValidFormatAndReader(file)) {
        return nullptr;
    }

    auto array = std::make_shared<Array>(file->InitData);
    auto reader = std::get<std::shared_ptr<Ship::BinaryReader>>(file->Reader);

    array->ArrayType = (ArrayResourceType)reader->ReadUInt32();
    array->ArrayCount = reader->ReadUInt32();

    for (uint32_t i = 0; i < array->ArrayCount; i++) {
        if (array->ArrayType == ArrayResourceType::Vertex) {
            // OTRTODO: Implement Vertex arrays as just a vertex resource.
            F3DVtx data;
            data.v.ob[0] = reader->ReadInt16();
            data.v.ob[1] = reader->ReadInt16();
            data.v.ob[2] = reader->ReadInt16();
            data.v.flag = reader->ReadUInt16();
            data.v.tc[0] = reader->ReadInt16();
            data.v.tc[1] = reader->ReadInt16();
            data.v.cn[0] = reader->ReadUByte();
            data.v.cn[1] = reader->ReadUByte();
            data.v.cn[2] = reader->ReadUByte();
            data.v.cn[3] = reader->ReadUByte();
            array->Vertices.push_back(data);
        } else {
            array->ArrayScalarType = (ScalarType)reader->ReadUInt32();

            int iter = 1;

            if (array->ArrayType == ArrayResourceType::Vector) {
                iter = reader->ReadUInt32();
            }

            for (int k = 0; k < iter; k++) {
                ScalarData data;

                switch (array->ArrayScalarType) {
                    case ScalarType::ZSCALAR_S8:
                        data.s8 = reader->ReadInt8();
                        break;
                    case ScalarType::ZSCALAR_U8:
                    case ScalarType::ZSCALAR_X8:
                        data.u8 = reader->ReadUByte();
                        break;
                    case ScalarType::ZSCALAR_S16:
                        data.s16 = reader->ReadInt16();
                        break;
                    case ScalarType::ZSCALAR_U16:
                    case ScalarType::ZSCALAR_X16:
                        data.u16 = reader->ReadUInt16();
                        break;
                    case ScalarType::ZSCALAR_S32:
                        data.s32 = reader->ReadInt32();
                        break;
                    case ScalarType::ZSCALAR_U32:
                    case ScalarType::ZSCALAR_X32:
                        data.u32 = reader->ReadUInt32();
                        break;
                    case ScalarType::ZSCALAR_S64:
                        data.s64 = reader->ReadInt64();
                        break;
                    case ScalarType::ZSCALAR_U64:
                    case ScalarType::ZSCALAR_X64:
                        data.u64 = reader->ReadUInt64();
                        break;
                    default:
                        // OTRTODO: IMPLEMENT OTHER TYPES!
                        break;
                }

                array->Scalars.push_back(data);
            }
        }
    }

    return array;
}
} // namespace SOH