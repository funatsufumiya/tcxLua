
// WARNING: This file is auto-generated!

#include "tcxLua.h"
#include "TrussC.h"

#include "sol/sol.hpp"
using namespace tc;

void tcxLua::setTrussCGeneratedBindings(const std::shared_ptr<sol::state>& lua){

// TrussC.h, LINE 337
lua->set_function("getDpiScale", [](){ trussc::getDpiScale(); });
// TrussC.h, LINE 342
lua->set_function("getFramebufferWidth", [](){ trussc::getFramebufferWidth(); });
// TrussC.h, LINE 346
lua->set_function("getFramebufferHeight", [](){ trussc::getFramebufferHeight(); });
// TrussC.h, LINE 357
lua->set_function("beginFrame", [](){ trussc::beginFrame(); });
// TrussC.h, LINE 373
// overloads: 4
// {'id': 'trussc#clear', 'filename': 'TrussC.h', 'line_number': 373, 'function_name': 'clear', 'params': [{'name': 'r', 'type': 'float'}, {'name': 'g', 'type': 'float'}, {'name': 'b', 'type': 'float'}, {'name': 'a', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 376
// overloads: 4
// {'id': 'trussc#clear', 'filename': 'TrussC.h', 'line_number': 376, 'function_name': 'clear', 'params': [], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 381
// overloads: 4
// {'id': 'trussc#clear', 'filename': 'TrussC.h', 'line_number': 381, 'function_name': 'clear', 'params': [{'name': 'gray', 'type': 'float'}, {'name': 'a', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 386
// overloads: 4
// {'id': 'trussc#clear', 'filename': 'TrussC.h', 'line_number': 386, 'function_name': 'clear', 'params': [{'name': 'c', 'type': 'const Color &'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 391
lua->set_function("flushDeferredShaderDraws", [](){ trussc::flushDeferredShaderDraws(); });
// TrussC.h, LINE 398
lua->set_function("ensureSwapchainPass", [](){ trussc::ensureSwapchainPass(); });
// TrussC.h, LINE 401
lua->set_function("present", [](){ trussc::present(); });
// TrussC.h, LINE 404
lua->set_function("isInSwapchainPass", [](){ trussc::isInSwapchainPass(); });
// TrussC.h, LINE 407
lua->set_function("suspendSwapchainPass", [](){ trussc::suspendSwapchainPass(); });
// TrussC.h, LINE 410
lua->set_function("resumeSwapchainPass", [](){ trussc::resumeSwapchainPass(); });
// TrussC.h, LINE 417
// overloads: 3
// {'id': 'trussc#setColor', 'filename': 'TrussC.h', 'line_number': 417, 'function_name': 'setColor', 'params': [{'name': 'r', 'type': 'float'}, {'name': 'g', 'type': 'float'}, {'name': 'b', 'type': 'float'}, {'name': 'a', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 422
// overloads: 3
// {'id': 'trussc#setColor', 'filename': 'TrussC.h', 'line_number': 422, 'function_name': 'setColor', 'params': [{'name': 'gray', 'type': 'float'}, {'name': 'a', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 427
// overloads: 3
// {'id': 'trussc#setColor', 'filename': 'TrussC.h', 'line_number': 427, 'function_name': 'setColor', 'params': [{'name': 'c', 'type': 'const Color &'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 432
lua->set_function("getColor", [](){ trussc::getColor(); });
// TrussC.h, LINE 437
lua->set_function("setColorHSB", [](float h, float s, float b, float a){ trussc::setColorHSB(h, s, b, a); });
// TrussC.h, LINE 442
lua->set_function("setColorOKLab", [](float L, float a_lab, float b_lab, float alpha){ trussc::setColorOKLab(L, a_lab, b_lab, alpha); });
// TrussC.h, LINE 447
lua->set_function("setColorOKLCH", [](float L, float C, float H, float alpha){ trussc::setColorOKLCH(L, C, H, alpha); });
// TrussC.h, LINE 452
lua->set_function("fill", [](){ trussc::fill(); });
// TrussC.h, LINE 457
lua->set_function("noFill", [](){ trussc::noFill(); });
// TrussC.h, LINE 462
lua->set_function("setStrokeWeight", [](float weight){ trussc::setStrokeWeight(weight); });
// TrussC.h, LINE 466
lua->set_function("getStrokeWeight", [](){ trussc::getStrokeWeight(); });
// TrussC.h, LINE 470
lua->set_function("setStrokeCap", [](StrokeCap cap){ trussc::setStrokeCap(cap); });
// TrussC.h, LINE 474
lua->set_function("getStrokeCap", [](){ trussc::getStrokeCap(); });
// TrussC.h, LINE 478
lua->set_function("setStrokeJoin", [](StrokeJoin join){ trussc::setStrokeJoin(join); });
// TrussC.h, LINE 482
lua->set_function("getStrokeJoin", [](){ trussc::getStrokeJoin(); });
// TrussC.h, LINE 505
// overloads: 2
// {'id': 'trussc#setScissor', 'filename': 'TrussC.h', 'line_number': 505, 'function_name': 'setScissor', 'params': [{'name': 'x', 'type': 'float'}, {'name': 'y', 'type': 'float'}, {'name': 'w', 'type': 'float'}, {'name': 'h', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 511
// overloads: 2
// {'id': 'trussc#setScissor', 'filename': 'TrussC.h', 'line_number': 511, 'function_name': 'setScissor', 'params': [{'name': 'x', 'type': 'int'}, {'name': 'y', 'type': 'int'}, {'name': 'w', 'type': 'int'}, {'name': 'h', 'type': 'int'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 516
lua->set_function("resetScissor", [](){ trussc::resetScissor(); });
// TrussC.h, LINE 522
lua->set_function("pushScissor", [](float x, float y, float w, float h){ trussc::pushScissor(x, y, w, h); });
// TrussC.h, LINE 540
lua->set_function("popScissor", [](){ trussc::popScissor(); });
// TrussC.h, LINE 562
lua->set_function("pushMatrix", [](){ trussc::pushMatrix(); });
// TrussC.h, LINE 567
lua->set_function("popMatrix", [](){ trussc::popMatrix(); });
// TrussC.h, LINE 572
lua->set_function("pushStyle", [](){ trussc::pushStyle(); });
// TrussC.h, LINE 577
lua->set_function("popStyle", [](){ trussc::popStyle(); });
// TrussC.h, LINE 582
lua->set_function("resetStyle", [](){ trussc::resetStyle(); });
// TrussC.h, LINE 587
// overloads: 3
// {'id': 'trussc#translate', 'filename': 'TrussC.h', 'line_number': 587, 'function_name': 'translate', 'params': [{'name': 'pos', 'type': 'Vec3'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 591
// overloads: 3
// {'id': 'trussc#translate', 'filename': 'TrussC.h', 'line_number': 591, 'function_name': 'translate', 'params': [{'name': 'x', 'type': 'float'}, {'name': 'y', 'type': 'float'}, {'name': 'z', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 595
// overloads: 3
// {'id': 'trussc#translate', 'filename': 'TrussC.h', 'line_number': 595, 'function_name': 'translate', 'params': [{'name': 'x', 'type': 'float'}, {'name': 'y', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 600
// overloads: 4
// {'id': 'trussc#rotate', 'filename': 'TrussC.h', 'line_number': 600, 'function_name': 'rotate', 'params': [{'name': 'radians', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 637
// overloads: 4
// {'id': 'trussc#rotate', 'filename': 'TrussC.h', 'line_number': 637, 'function_name': 'rotate', 'params': [{'name': 'x', 'type': 'float'}, {'name': 'y', 'type': 'float'}, {'name': 'z', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 643
// overloads: 4
// {'id': 'trussc#rotate', 'filename': 'TrussC.h', 'line_number': 643, 'function_name': 'rotate', 'params': [{'name': 'euler', 'type': 'const Vec3 &'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 647
// overloads: 4
// {'id': 'trussc#rotate', 'filename': 'TrussC.h', 'line_number': 647, 'function_name': 'rotate', 'params': [{'name': 'quat', 'type': 'const Quaternion &'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 605
lua->set_function("rotateX", [](float radians){ trussc::rotateX(radians); });
// TrussC.h, LINE 610
lua->set_function("rotateY", [](float radians){ trussc::rotateY(radians); });
// TrussC.h, LINE 615
lua->set_function("rotateZ", [](float radians){ trussc::rotateZ(radians); });
// TrussC.h, LINE 620
// overloads: 3
// {'id': 'trussc#rotateDeg', 'filename': 'TrussC.h', 'line_number': 620, 'function_name': 'rotateDeg', 'params': [{'name': 'degrees', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 652
// overloads: 3
// {'id': 'trussc#rotateDeg', 'filename': 'TrussC.h', 'line_number': 652, 'function_name': 'rotateDeg', 'params': [{'name': 'x', 'type': 'float'}, {'name': 'y', 'type': 'float'}, {'name': 'z', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 658
// overloads: 3
// {'id': 'trussc#rotateDeg', 'filename': 'TrussC.h', 'line_number': 658, 'function_name': 'rotateDeg', 'params': [{'name': 'euler', 'type': 'const Vec3 &'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 624
lua->set_function("rotateXDeg", [](float degrees){ trussc::rotateXDeg(degrees); });
// TrussC.h, LINE 628
lua->set_function("rotateYDeg", [](float degrees){ trussc::rotateYDeg(degrees); });
// TrussC.h, LINE 632
lua->set_function("rotateZDeg", [](float degrees){ trussc::rotateZDeg(degrees); });
// TrussC.h, LINE 663
// overloads: 3
// {'id': 'trussc#scale', 'filename': 'TrussC.h', 'line_number': 663, 'function_name': 'scale', 'params': [{'name': 's', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 668
// overloads: 3
// {'id': 'trussc#scale', 'filename': 'TrussC.h', 'line_number': 668, 'function_name': 'scale', 'params': [{'name': 'sx', 'type': 'float'}, {'name': 'sy', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 673
// overloads: 3
// {'id': 'trussc#scale', 'filename': 'TrussC.h', 'line_number': 673, 'function_name': 'scale', 'params': [{'name': 'sx', 'type': 'float'}, {'name': 'sy', 'type': 'float'}, {'name': 'sz', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 678
lua->set_function("getCurrentMatrix", [](){ trussc::getCurrentMatrix(); });
// TrussC.h, LINE 683
lua->set_function("resetMatrix", [](){ trussc::resetMatrix(); });
// TrussC.h, LINE 688
lua->set_function("setMatrix", [](const Mat4 & mat){ trussc::setMatrix(mat); });
// TrussC.h, LINE 698
lua->set_function("setBlendMode", [](BlendMode mode){ trussc::setBlendMode(mode); });
// TrussC.h, LINE 707
lua->set_function("getBlendMode", [](){ trussc::getBlendMode(); });
// TrussC.h, LINE 712
lua->set_function("resetBlendMode", [](){ trussc::resetBlendMode(); });
// TrussC.h, LINE 717
lua->set_function("restoreBlendPipeline", [](){ trussc::restoreBlendPipeline(); });
// TrussC.h, LINE 730
lua->set_function("enable3D", [](){ trussc::enable3D(); });
// TrussC.h, LINE 739
lua->set_function("enable3DPerspective", [](float fovY, float nearZ, float farZ){ trussc::enable3DPerspective(fovY, nearZ, farZ); });
// TrussC.h, LINE 860
lua->set_function("setupScreenFov", [](float fovDeg, float nearDist, float farDist){ trussc::setupScreenFov(fovDeg, nearDist, farDist); });
// TrussC.h, LINE 867
lua->set_function("setupScreenPerspective", [](float fovDeg, float nearDist, float farDist){ trussc::setupScreenPerspective(fovDeg, nearDist, farDist); });
// TrussC.h, LINE 872
lua->set_function("setupScreenOrtho", [](){ trussc::setupScreenOrtho(); });
// TrussC.h, LINE 878
lua->set_function("setDefaultScreenFov", [](float fovDeg){ trussc::setDefaultScreenFov(fovDeg); });
// TrussC.h, LINE 882
lua->set_function("getDefaultScreenFov", [](){ trussc::getDefaultScreenFov(); });
// TrussC.h, LINE 887
lua->set_function("setNearClip", [](float nearDist){ trussc::setNearClip(nearDist); });
// TrussC.h, LINE 891
lua->set_function("setFarClip", [](float farDist){ trussc::setFarClip(farDist); });
// TrussC.h, LINE 895
lua->set_function("getNearClip", [](){ trussc::getNearClip(); });
// TrussC.h, LINE 899
lua->set_function("getFarClip", [](){ trussc::getFarClip(); });
// TrussC.h, LINE 909
lua->set_function("worldToScreen", [](const Vec3 & worldPos){ trussc::worldToScreen(worldPos); });
// TrussC.h, LINE 938
lua->set_function("screenToWorld", [](const Vec2 & screenPos, float worldZ){ trussc::screenToWorld(screenPos, worldZ); });
// TrussC.h, LINE 984
lua->set_function("disable3D", [](){ trussc::disable3D(); });
// TrussC.h, LINE 993
// overloads: 3
// {'id': 'trussc#drawRect', 'filename': 'TrussC.h', 'line_number': 993, 'function_name': 'drawRect', 'params': [{'name': 'pos', 'type': 'Vec3'}, {'name': 'size', 'type': 'Vec2'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 997
// overloads: 3
// {'id': 'trussc#drawRect', 'filename': 'TrussC.h', 'line_number': 997, 'function_name': 'drawRect', 'params': [{'name': 'pos', 'type': 'Vec3'}, {'name': 'w', 'type': 'float'}, {'name': 'h', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 1001
// overloads: 3
// {'id': 'trussc#drawRect', 'filename': 'TrussC.h', 'line_number': 1001, 'function_name': 'drawRect', 'params': [{'name': 'x', 'type': 'float'}, {'name': 'y', 'type': 'float'}, {'name': 'w', 'type': 'float'}, {'name': 'h', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 1006
// overloads: 2
// {'id': 'trussc#drawRectRounded', 'filename': 'TrussC.h', 'line_number': 1006, 'function_name': 'drawRectRounded', 'params': [{'name': 'pos', 'type': 'Vec3'}, {'name': 'size', 'type': 'Vec2'}, {'name': 'radius', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 1010
// overloads: 2
// {'id': 'trussc#drawRectRounded', 'filename': 'TrussC.h', 'line_number': 1010, 'function_name': 'drawRectRounded', 'params': [{'name': 'x', 'type': 'float'}, {'name': 'y', 'type': 'float'}, {'name': 'w', 'type': 'float'}, {'name': 'h', 'type': 'float'}, {'name': 'radius', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 1015
// overloads: 2
// {'id': 'trussc#drawRectSquircle', 'filename': 'TrussC.h', 'line_number': 1015, 'function_name': 'drawRectSquircle', 'params': [{'name': 'pos', 'type': 'Vec3'}, {'name': 'size', 'type': 'Vec2'}, {'name': 'radius', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 1019
// overloads: 2
// {'id': 'trussc#drawRectSquircle', 'filename': 'TrussC.h', 'line_number': 1019, 'function_name': 'drawRectSquircle', 'params': [{'name': 'x', 'type': 'float'}, {'name': 'y', 'type': 'float'}, {'name': 'w', 'type': 'float'}, {'name': 'h', 'type': 'float'}, {'name': 'radius', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 1024
// overloads: 2
// {'id': 'trussc#drawCircle', 'filename': 'TrussC.h', 'line_number': 1024, 'function_name': 'drawCircle', 'params': [{'name': 'center', 'type': 'Vec3'}, {'name': 'radius', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 1028
// overloads: 2
// {'id': 'trussc#drawCircle', 'filename': 'TrussC.h', 'line_number': 1028, 'function_name': 'drawCircle', 'params': [{'name': 'cx', 'type': 'float'}, {'name': 'cy', 'type': 'float'}, {'name': 'radius', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 1033
// overloads: 3
// {'id': 'trussc#drawEllipse', 'filename': 'TrussC.h', 'line_number': 1033, 'function_name': 'drawEllipse', 'params': [{'name': 'center', 'type': 'Vec3'}, {'name': 'radii', 'type': 'Vec2'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 1037
// overloads: 3
// {'id': 'trussc#drawEllipse', 'filename': 'TrussC.h', 'line_number': 1037, 'function_name': 'drawEllipse', 'params': [{'name': 'center', 'type': 'Vec3'}, {'name': 'rx', 'type': 'float'}, {'name': 'ry', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 1041
// overloads: 3
// {'id': 'trussc#drawEllipse', 'filename': 'TrussC.h', 'line_number': 1041, 'function_name': 'drawEllipse', 'params': [{'name': 'cx', 'type': 'float'}, {'name': 'cy', 'type': 'float'}, {'name': 'rx', 'type': 'float'}, {'name': 'ry', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 1046
// overloads: 3
// {'id': 'trussc#drawLine', 'filename': 'TrussC.h', 'line_number': 1046, 'function_name': 'drawLine', 'params': [{'name': 'p1', 'type': 'Vec3'}, {'name': 'p2', 'type': 'Vec3'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 1050
// overloads: 3
// {'id': 'trussc#drawLine', 'filename': 'TrussC.h', 'line_number': 1050, 'function_name': 'drawLine', 'params': [{'name': 'x1', 'type': 'float'}, {'name': 'y1', 'type': 'float'}, {'name': 'x2', 'type': 'float'}, {'name': 'y2', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 1054
// overloads: 3
// {'id': 'trussc#drawLine', 'filename': 'TrussC.h', 'line_number': 1054, 'function_name': 'drawLine', 'params': [{'name': 'x1', 'type': 'float'}, {'name': 'y1', 'type': 'float'}, {'name': 'z1', 'type': 'float'}, {'name': 'x2', 'type': 'float'}, {'name': 'y2', 'type': 'float'}, {'name': 'z2', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 1059
// overloads: 2
// {'id': 'trussc#drawTriangle', 'filename': 'TrussC.h', 'line_number': 1059, 'function_name': 'drawTriangle', 'params': [{'name': 'p1', 'type': 'Vec3'}, {'name': 'p2', 'type': 'Vec3'}, {'name': 'p3', 'type': 'Vec3'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 1063
// overloads: 2
// {'id': 'trussc#drawTriangle', 'filename': 'TrussC.h', 'line_number': 1063, 'function_name': 'drawTriangle', 'params': [{'name': 'x1', 'type': 'float'}, {'name': 'y1', 'type': 'float'}, {'name': 'x2', 'type': 'float'}, {'name': 'y2', 'type': 'float'}, {'name': 'x3', 'type': 'float'}, {'name': 'y3', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 1068
// overloads: 2
// {'id': 'trussc#drawPoint', 'filename': 'TrussC.h', 'line_number': 1068, 'function_name': 'drawPoint', 'params': [{'name': 'pos', 'type': 'Vec3'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 1072
// overloads: 2
// {'id': 'trussc#drawPoint', 'filename': 'TrussC.h', 'line_number': 1072, 'function_name': 'drawPoint', 'params': [{'name': 'x', 'type': 'float'}, {'name': 'y', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 1077
lua->set_function("setCircleResolution", [](int res){ trussc::setCircleResolution(res); });
// TrussC.h, LINE 1081
lua->set_function("getCircleResolution", [](){ trussc::getCircleResolution(); });
// TrussC.h, LINE 1086
lua->set_function("isFillEnabled", [](){ trussc::isFillEnabled(); });
// TrussC.h, LINE 1090
lua->set_function("isStrokeEnabled", [](){ trussc::isStrokeEnabled(); });
// TrussC.h, LINE 1124
// overloads: 6
// {'id': 'trussc#drawBitmapString', 'filename': 'TrussC.h', 'line_number': 1124, 'function_name': 'drawBitmapString', 'params': [{'name': 'text', 'type': 'const std::string &'}, {'name': 'pos', 'type': 'Vec3'}, {'name': 'screenFixed', 'type': 'bool'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 1128
// overloads: 6
// {'id': 'trussc#drawBitmapString', 'filename': 'TrussC.h', 'line_number': 1128, 'function_name': 'drawBitmapString', 'params': [{'name': 'text', 'type': 'const std::string &'}, {'name': 'x', 'type': 'float'}, {'name': 'y', 'type': 'float'}, {'name': 'screenFixed', 'type': 'bool'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 1133
// overloads: 6
// {'id': 'trussc#drawBitmapString', 'filename': 'TrussC.h', 'line_number': 1133, 'function_name': 'drawBitmapString', 'params': [{'name': 'text', 'type': 'const std::string &'}, {'name': 'pos', 'type': 'Vec3'}, {'name': 'scale', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 1137
// overloads: 6
// {'id': 'trussc#drawBitmapString', 'filename': 'TrussC.h', 'line_number': 1137, 'function_name': 'drawBitmapString', 'params': [{'name': 'text', 'type': 'const std::string &'}, {'name': 'x', 'type': 'float'}, {'name': 'y', 'type': 'float'}, {'name': 'scale', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 1142
// overloads: 6
// {'id': 'trussc#drawBitmapString', 'filename': 'TrussC.h', 'line_number': 1142, 'function_name': 'drawBitmapString', 'params': [{'name': 'text', 'type': 'const std::string &'}, {'name': 'pos', 'type': 'Vec3'}, {'name': 'h', 'type': 'Direction'}, {'name': 'v', 'type': 'Direction'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 1147
// overloads: 6
// {'id': 'trussc#drawBitmapString', 'filename': 'TrussC.h', 'line_number': 1147, 'function_name': 'drawBitmapString', 'params': [{'name': 'text', 'type': 'const std::string &'}, {'name': 'x', 'type': 'float'}, {'name': 'y', 'type': 'float'}, {'name': 'h', 'type': 'Direction'}, {'name': 'v', 'type': 'Direction'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 1153
lua->set_function("setTextAlign", [](Direction h, Direction v){ trussc::setTextAlign(h, v); });
// TrussC.h, LINE 1158
lua->set_function("getTextAlignH", [](){ trussc::getTextAlignH(); });
// TrussC.h, LINE 1162
lua->set_function("getTextAlignV", [](){ trussc::getTextAlignV(); });
// TrussC.h, LINE 1167
lua->set_function("setBitmapLineHeight", [](float h){ trussc::setBitmapLineHeight(h); });
// TrussC.h, LINE 1172
lua->set_function("getBitmapLineHeight", [](){ trussc::getBitmapLineHeight(); });
// TrussC.h, LINE 1177
lua->set_function("getBitmapFontHeight", [](){ trussc::getBitmapFontHeight(); });
// TrussC.h, LINE 1182
lua->set_function("getBitmapStringWidth", [](const std::string & text){ trussc::getBitmapStringWidth(text); });
// TrussC.h, LINE 1187
lua->set_function("getBitmapStringHeight", [](const std::string & text){ trussc::getBitmapStringHeight(text); });
// TrussC.h, LINE 1192
lua->set_function("getBitmapStringBBox", [](const std::string & text){ trussc::getBitmapStringBBox(text); });
// TrussC.h, LINE 1197
lua->set_function("drawBitmapStringHighlight", [](const std::string & text, float x, float y, const Color & background, const Color & foreground){ trussc::drawBitmapStringHighlight(text, x, y, background, foreground); });
// TrussC.h, LINE 1303
lua->set_function("setWindowTitle", [](const std::string & title){ trussc::setWindowTitle(title); });
// TrussC.h, LINE 1343
lua->set_function("showCursor", [](){ trussc::showCursor(); });
// TrussC.h, LINE 1348
lua->set_function("hideCursor", [](){ trussc::hideCursor(); });
// TrussC.h, LINE 1353
lua->set_function("setCursor", [](Cursor cursor){ trussc::setCursor(cursor); });
// TrussC.h, LINE 1358
lua->set_function("getCursor", [](){ trussc::getCursor(); });
// TrussC.h, LINE 1364
// overloads: 2
// {'id': 'trussc#bindCursorImage', 'filename': 'TrussC.h', 'line_number': 1364, 'function_name': 'bindCursorImage', 'params': [{'name': 'cursor', 'type': 'Cursor'}, {'name': 'width', 'type': 'int'}, {'name': 'height', 'type': 'int'}, {'name': 'pixels', 'type': 'const unsigned char *'}, {'name': 'hotspotX', 'type': 'int'}, {'name': 'hotspotY', 'type': 'int'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 2518
// overloads: 2
// {'id': 'trussc#bindCursorImage', 'filename': 'TrussC.h', 'line_number': 2518, 'function_name': 'bindCursorImage', 'params': [{'name': 'cursor', 'type': 'Cursor'}, {'name': 'image', 'type': 'const Image &'}, {'name': 'hotspotX', 'type': 'int'}, {'name': 'hotspotY', 'type': 'int'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 1380
lua->set_function("unbindCursorImage", [](Cursor cursor){ trussc::unbindCursorImage(cursor); });
// TrussC.h, LINE 1389
lua->set_function("setClipboardString", [](const std::string & text){ trussc::setClipboardString(text); });
// TrussC.h, LINE 1398
lua->set_function("getClipboardString", [](){ trussc::getClipboardString(); });
// TrussC.h, LINE 1406
lua->set_function("setWindowSize", [](int width, int height){ trussc::setWindowSize(width, height); });
// TrussC.h, LINE 1418
lua->set_function("setFullscreen", [](bool full){ trussc::setFullscreen(full); });
// TrussC.h, LINE 1425
lua->set_function("isFullscreen", [](){ trussc::isFullscreen(); });
// TrussC.h, LINE 1430
lua->set_function("toggleFullscreen", [](){ trussc::toggleFullscreen(); });
// TrussC.h, LINE 1456
lua->set_function("setOrientation", [](Orientation mask){ trussc::setOrientation(mask); });
// TrussC.h, LINE 1465
lua->set_function("getWindowWidth", [](){ trussc::getWindowWidth(); });
// TrussC.h, LINE 1473
lua->set_function("getWindowHeight", [](){ trussc::getWindowHeight(); });
// TrussC.h, LINE 1481
lua->set_function("getWindowSize", [](){ trussc::getWindowSize(); });
// TrussC.h, LINE 1486
lua->set_function("getAspectRatio", [](){ trussc::getAspectRatio(); });
// TrussC.h, LINE 1494
lua->set_function("getElapsedTime", [](){ trussc::getElapsedTime(); });
// TrussC.h, LINE 1507
lua->set_function("getUpdateCount", [](){ trussc::getUpdateCount(); });
// TrussC.h, LINE 1512
lua->set_function("getDrawCount", [](){ trussc::getDrawCount(); });
// TrussC.h, LINE 1517
lua->set_function("getFrameCount", [](){ trussc::getFrameCount(); });
// TrussC.h, LINE 1521
lua->set_function("getDeltaTime", [](){ trussc::getDeltaTime(); });
// TrussC.h, LINE 1526
lua->set_function("getFrameRate", [](){ trussc::getFrameRate(); });
// TrussC.h, LINE 1553
lua->set_function("getSokolMemoryBytes", [](){ trussc::getSokolMemoryBytes(); });
// TrussC.h, LINE 1556
lua->set_function("getSokolMemoryAllocs", [](){ trussc::getSokolMemoryAllocs(); });
// TrussC.h, LINE 1561
lua->set_function("releaseSglBuffers", [](){ trussc::releaseSglBuffers(); });
// TrussC.h, LINE 1570
lua->set_function("getGlobalMouseX", [](){ trussc::getGlobalMouseX(); });
// TrussC.h, LINE 1575
lua->set_function("getGlobalMouseY", [](){ trussc::getGlobalMouseY(); });
// TrussC.h, LINE 1580
lua->set_function("getGlobalPMouseX", [](){ trussc::getGlobalPMouseX(); });
// TrussC.h, LINE 1585
lua->set_function("getGlobalPMouseY", [](){ trussc::getGlobalPMouseY(); });
// TrussC.h, LINE 1590
lua->set_function("isMousePressed", [](){ trussc::isMousePressed(); });
// TrussC.h, LINE 1595
lua->set_function("getMouseButton", [](){ trussc::getMouseButton(); });
// TrussC.h, LINE 1600
lua->set_function("isKeyPressed", [](int key){ trussc::isKeyPressed(key); });
// TrussC.h, LINE 1605
lua->set_function("getMouseX", [](){ trussc::getMouseX(); });
// TrussC.h, LINE 1606
lua->set_function("getMouseY", [](){ trussc::getMouseY(); });
// TrussC.h, LINE 1607
lua->set_function("getMousePos", [](){ trussc::getMousePos(); });
// TrussC.h, LINE 1608
lua->set_function("getGlobalMousePos", [](){ trussc::getGlobalMousePos(); });
// TrussC.h, LINE 1616
lua->set_function("setTouchAsMouse", [](bool enabled){ trussc::setTouchAsMouse(enabled); });
// TrussC.h, LINE 1617
lua->set_function("getTouchAsMouse", [](){ trussc::getTouchAsMouse(); });
// TrussC.h, LINE 1624
lua->set_function("getBackendName", [](){ trussc::getBackendName(); });
// TrussC.h, LINE 1638
lua->set_function("getMemoryUsage", [](){ trussc::getMemoryUsage(); });
// TrussC.h, LINE 1678
lua->set_function("getNodeCount", [](){ trussc::getNodeCount(); });
// TrussC.h, LINE 1679
lua->set_function("getTextureCount", [](){ trussc::getTextureCount(); });
// TrussC.h, LINE 1680
lua->set_function("getFboCount", [](){ trussc::getFboCount(); });
// TrussC.h, LINE 1704
lua->set_function("setFps", [](float fps){ trussc::setFps(fps); });
// TrussC.h, LINE 1714
lua->set_function("setIndependentFps", [](float updateFps, float drawFps){ trussc::setIndependentFps(updateFps, drawFps); });
// TrussC.h, LINE 1723
lua->set_function("getFpsSettings", [](){ trussc::getFpsSettings(); });
// TrussC.h, LINE 1743
lua->set_function("getFps", [](){ trussc::getFps(); });
// TrussC.h, LINE 1749
lua->set_function("redraw", [](int count){ trussc::redraw(count); });
// TrussC.h, LINE 1757
lua->set_function("requestExitApp", [](){ trussc::requestExitApp(); });
// TrussC.h, LINE 1763
lua->set_function("exitApp", [](){ trussc::exitApp(); });
// TrussC.h, LINE 1773
lua->set_function("grabScreen", [](Pixels & outPixels){ trussc::grabScreen(outPixels); });
// TrussC.h, LINE 1912
lua->set_function("registerInspectionTools", [](){ trussc::mcp::registerInspectionTools(); });
// TrussC.h, LINE 1913
lua->set_function("registerDebuggerTools", [](){ trussc::mcp::registerDebuggerTools(); });
// TrussC.h, LINE 2562
// overloads: 6
// {'id': 'trussc#drawBox', 'filename': 'TrussC.h', 'line_number': 2562, 'function_name': 'drawBox', 'params': [{'name': 'w', 'type': 'float'}, {'name': 'h', 'type': 'float'}, {'name': 'd', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 2571
// overloads: 6
// {'id': 'trussc#drawBox', 'filename': 'TrussC.h', 'line_number': 2571, 'function_name': 'drawBox', 'params': [{'name': 'size', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 2575
// overloads: 6
// {'id': 'trussc#drawBox', 'filename': 'TrussC.h', 'line_number': 2575, 'function_name': 'drawBox', 'params': [{'name': 'pos', 'type': 'Vec3'}, {'name': 'w', 'type': 'float'}, {'name': 'h', 'type': 'float'}, {'name': 'd', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 2582
// overloads: 6
// {'id': 'trussc#drawBox', 'filename': 'TrussC.h', 'line_number': 2582, 'function_name': 'drawBox', 'params': [{'name': 'x', 'type': 'float'}, {'name': 'y', 'type': 'float'}, {'name': 'z', 'type': 'float'}, {'name': 'w', 'type': 'float'}, {'name': 'h', 'type': 'float'}, {'name': 'd', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 2586
// overloads: 6
// {'id': 'trussc#drawBox', 'filename': 'TrussC.h', 'line_number': 2586, 'function_name': 'drawBox', 'params': [{'name': 'pos', 'type': 'Vec3'}, {'name': 'size', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 2590
// overloads: 6
// {'id': 'trussc#drawBox', 'filename': 'TrussC.h', 'line_number': 2590, 'function_name': 'drawBox', 'params': [{'name': 'x', 'type': 'float'}, {'name': 'y', 'type': 'float'}, {'name': 'z', 'type': 'float'}, {'name': 'size', 'type': 'float'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 2594
// overloads: 3
// {'id': 'trussc#drawSphere', 'filename': 'TrussC.h', 'line_number': 2594, 'function_name': 'drawSphere', 'params': [{'name': 'radius', 'type': 'float'}, {'name': 'resolution', 'type': 'int'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 2603
// overloads: 3
// {'id': 'trussc#drawSphere', 'filename': 'TrussC.h', 'line_number': 2603, 'function_name': 'drawSphere', 'params': [{'name': 'pos', 'type': 'Vec3'}, {'name': 'radius', 'type': 'float'}, {'name': 'resolution', 'type': 'int'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 2610
// overloads: 3
// {'id': 'trussc#drawSphere', 'filename': 'TrussC.h', 'line_number': 2610, 'function_name': 'drawSphere', 'params': [{'name': 'x', 'type': 'float'}, {'name': 'y', 'type': 'float'}, {'name': 'z', 'type': 'float'}, {'name': 'radius', 'type': 'float'}, {'name': 'resolution', 'type': 'int'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 2614
// overloads: 3
// {'id': 'trussc#drawCone', 'filename': 'TrussC.h', 'line_number': 2614, 'function_name': 'drawCone', 'params': [{'name': 'radius', 'type': 'float'}, {'name': 'height', 'type': 'float'}, {'name': 'resolution', 'type': 'int'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 2623
// overloads: 3
// {'id': 'trussc#drawCone', 'filename': 'TrussC.h', 'line_number': 2623, 'function_name': 'drawCone', 'params': [{'name': 'pos', 'type': 'Vec3'}, {'name': 'radius', 'type': 'float'}, {'name': 'height', 'type': 'float'}, {'name': 'resolution', 'type': 'int'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}
// TrussC.h, LINE 2630
// overloads: 3
// {'id': 'trussc#drawCone', 'filename': 'TrussC.h', 'line_number': 2630, 'function_name': 'drawCone', 'params': [{'name': 'x', 'type': 'float'}, {'name': 'y', 'type': 'float'}, {'name': 'z', 'type': 'float'}, {'name': 'radius', 'type': 'float'}, {'name': 'height', 'type': 'float'}, {'name': 'resolution', 'type': 'int'}], 'return_type': 'void', 'namespace': 'trussc', 'class': ''}


}
