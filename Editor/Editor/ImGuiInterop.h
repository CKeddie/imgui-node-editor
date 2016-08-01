#pragma once
#include "imgui/imgui.h"
#include "Types.h"

namespace ax {
namespace ImGuiInterop {

static inline ImVec2 operator+(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x+rhs.x, lhs.y+rhs.y); }
static inline ImVec2 operator-(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x-rhs.x, lhs.y-rhs.y); }
static inline ImVec2 operator*(const ImVec2& lhs, float rhs)         { return ImVec2(lhs.x * rhs,   lhs.y * rhs); }
static inline ImVec2 operator*(float lhs,         const ImVec2& rhs) { return ImVec2(lhs   * rhs.x, lhs   * rhs.y); }

static inline int    roundi(float value)            { return static_cast<int>(value); }
static inline point  to_point(const ImVec2& value)  { return point(roundi(value.x), roundi(value.y)); }
static inline pointf to_pointf(const ImVec2& value) { return pointf(value.x, value.y); }
static inline pointf to_pointf(const point& value)  { return pointf(static_cast<float>(value.x), static_cast<float>(value.y)); }
static inline size   to_size (const ImVec2& value)  { return size (roundi(value.x), roundi(value.y)); }
static inline ImVec2 to_imvec(const point& value)   { return ImVec2(static_cast<float>(value.x), static_cast<float>(value.y)); }
static inline ImVec2 to_imvec(const pointf& value)  { return ImVec2(value.x, value.y); }
static inline ImVec2 to_imvec(const size& value)    { return ImVec2(static_cast<float>(value.w), static_cast<float>(value.h)); }
static inline rect   get_item_bounds()              { return rect(to_point(ImGui::GetItemRectMin()), to_point(ImGui::GetItemRectMax())); }

} // namespace ImGuiInterop
} // namespace ax