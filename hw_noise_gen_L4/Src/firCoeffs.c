#include "arm_math.h"

//Band-pass filter 300-3400 Hz

float32_t firCoeffs_fb[129] = {
-0.000153808, -0.000161041, +0.000220957, +0.000665287, +0.000754024, +0.000397839, -2.2429e-05, +1.5024e-05, 
+0.00062985, +0.00132651, +0.00142091, +0.000774123, +7.02552e-05, +0.000213259, +0.00133364, +0.00246492, 
+0.00241635, +0.00109483, -0.000159281, +0.000178519, +0.00209801, +0.00375555, +0.00322231, +0.000666764, 
-0.00145002, -0.000759226, +0.00230498, +0.00449937, +0.00294929, -0.00154871, -0.00481604, -0.00343955, 
+0.00127044, +0.00399448, +0.000725849, -0.00654744, -0.0111383, -0.00839759, -0.00120019, +0.00211971, 
-0.00378481, -0.0148783, -0.0208014, -0.0154015, -0.00419376, -3.81471e-05, -0.0100208, -0.02667, 
-0.0338679, -0.0232778, -0.00491847, +0.000707584, -0.0165453, -0.043174, -0.0521882, -0.0301789, 
+0.00459797, +0.0144414, -0.0215081, -0.0790935, -0.0992069, -0.0342215, +0.105936, +0.249658, 
+0.31039, +0.249658, +0.105936, -0.0342215, -0.0992069, -0.0790935, -0.0215081, +0.0144414, 
+0.00459797, -0.0301789, -0.0521882, -0.043174, -0.0165453, +0.000707584, -0.00491847, -0.0232778, 
-0.0338679, -0.02667, -0.0100208, -3.81471e-05, -0.00419376, -0.0154015, -0.0208014, -0.0148783, 
-0.00378481, +0.00211971, -0.00120019, -0.00839759, -0.0111383, -0.00654744, +0.000725849, +0.00399448, 
+0.00127044, -0.00343955, -0.00481604, -0.00154871, +0.00294929, +0.00449937, +0.00230498, -0.000759226, 
-0.00145002, +0.000666764, +0.00322231, +0.00375555, +0.00209801, +0.000178519, -0.000159281, +0.00109483, 
+0.00241635, +0.00246492, +0.00133364, +0.000213259, +7.02552e-05, +0.000774123, +0.00142091, +0.00132651, 
+0.00062985, +1.5024e-05, -2.2429e-05, +0.000397839, +0.000754024, +0.000665287, +0.000220957, -0.000161041, 
-0.000153808};

//Band-pass filter 300-1850 Hz

float32_t firCoeffs_hb[129] = {
-8.27319e-05, -0.000178891, -0.000155201, +3.64344e-06, +0.000277329, +0.000609702, +0.000918121, +0.00111345, 
+0.001128, +0.000944161, +0.000613056, +0.000252776, +2.08144e-05, +6.41994e-05, +0.000461073, +0.00117458, 
+0.00204018, +0.00279916, +0.00317543, +0.0029752, +0.00217544, +0.00096499, -0.000286884, -0.001136, 
-0.00121653, -0.000392548, +0.00114951, +0.00291224, +0.00421578, +0.00441488, +0.00313883, +0.000469418, 
-0.00301769, -0.00638424, -0.00861164, -0.00895454, -0.00724899, -0.00405788, -0.000578558, +0.00168858, 
+0.00142702, -0.00200308, -0.00823841, -0.0158891, -0.0228692, -0.0270157, -0.0268245, -0.0220686, 
-0.0140739, -0.00551095, +0.000294054, +0.00037258, -0.00683098, -0.0206904, -0.0381918, -0.0544229, 
-0.0636952, -0.0610371, -0.0436667, -0.0120245, +0.0299584, +0.0754869, +0.11631, +0.144578, 
+0.154678, +0.144578, +0.11631, +0.0754869, +0.0299584, -0.0120245, -0.0436667, -0.0610371, 
-0.0636952, -0.0544229, -0.0381918, -0.0206904, -0.00683098, +0.00037258, +0.000294054, -0.00551095, 
-0.0140739, -0.0220686, -0.0268245, -0.0270157, -0.0228692, -0.0158891, -0.00823841, -0.00200308, 
+0.00142702, +0.00168858, -0.000578558, -0.00405788, -0.00724899, -0.00895454, -0.00861164, -0.00638424, 
-0.00301769, +0.000469418, +0.00313883, +0.00441488, +0.00421578, +0.00291224, +0.00114951, -0.000392548, 
-0.00121653, -0.001136, -0.000286884, +0.00096499, +0.00217544, +0.0029752, +0.00317543, +0.00279916, 
+0.00204018, +0.00117458, +0.000461073, +6.41994e-05, +2.08144e-05, +0.000252776, +0.000613056, +0.000944161, 
+0.001128, +0.00111345, +0.000918121, +0.000609702, +0.000277329, +3.64344e-06, -0.000155201, -0.000178891, 
-8.27319e-05};

//Band-pass filter 3500-5000 Hz

float32_t firCoeffs_oob[129] = {
-0.000422071, -0.000386003, +0.000459501, +0.000785073, -0.000172548, -0.000980674, -0.000278923, +0.000783007, 
+0.000530739, -0.000297667, -0.00023266, -4.15838e-06, -0.000585985, -0.000431467, +0.00133298, +0.00168626, 
-0.00120099, -0.00303672, -5.1685e-05, +0.00335845, +0.00156677, -0.00217297, -0.001825, +0.00045169, 
-1.02573e-06, -0.00018303, +0.00288764, +0.00267851, -0.00432138, -0.00695471, +0.00235816, +0.00992633, 
+0.00217916, -0.00883424, -0.00558928, +0.00415699, +0.00406012, -0.000209988, +0.00256452, +0.00211413, 
-0.00946136, -0.0110326, +0.00998276, +0.0218172, -0.00154968, -0.0260463, -0.0105628, +0.0191369, 
+0.0157252, -0.00607375, -0.0062272, +0.00014598, -0.0145086, -0.0139196, +0.0309353, +0.0481936, 
-0.024208, -0.0875836, -0.0141652, +0.107599, +0.0735687, -0.0898088, -0.127773, +0.035037, 
+0.149653, +0.035037, -0.127773, -0.0898088, +0.0735687, +0.107599, -0.0141652, -0.0875836, 
-0.024208, +0.0481936, +0.0309353, -0.0139196, -0.0145086, +0.00014598, -0.0062272, -0.00607375, 
+0.0157252, +0.0191369, -0.0105628, -0.0260463, -0.00154968, +0.0218172, +0.00998276, -0.0110326, 
-0.00946136, +0.00211413, +0.00256452, -0.000209988, +0.00406012, +0.00415699, -0.00558928, -0.00883424, 
+0.00217916, +0.00992633, +0.00235816, -0.00695471, -0.00432138, +0.00267851, +0.00288764, -0.00018303, 
-1.02573e-06, +0.00045169, -0.001825, -0.00217297, +0.00156677, +0.00335845, -5.1685e-05, -0.00303672, 
-0.00120099, +0.00168626, +0.00133298, -0.000431467, -0.000585985, -4.15838e-06, -0.00023266, -0.000297667, 
+0.000530739, +0.000783007, -0.000278923, -0.000980674, -0.000172548, +0.000785073, +0.000459501, -0.000386003, 
-0.000422071};

//test
float32_t test[81] = {
+7.80308e-05, +0.000409181, +0.000525844, +0.0003382, -9.10686e-05, -0.000548471, -0.000754466, -0.000515158, 
+0.000129424, +0.000861569, +0.00121518, +0.000847577, -0.000190868, -0.00137996, -0.0019569, -0.00137383, 
+0.00027183, +0.00214077, +0.0030394, +0.00214216, -0.000367605, -0.00319281, -0.00454317, -0.0032187, 
+0.000472626, +0.00460843, +0.00658907, +0.00470399, -0.00058079, -0.00650807, -0.00938023, -0.00676893, 
+0.000685811, +0.00911591, +0.0133, +0.00974203, -0.000781586, -0.0129042, -0.0191781, -0.0143583, 
+0.000862548, +0.0190516, +0.0291947, +0.0226717, -0.000923992, -0.0314709, -0.051398, -0.0433463, 
+0.000962348, +0.0750537, +0.158428, +0.223929, +0.248723, +0.223929, +0.158428, +0.0750537, 
+0.000962348, -0.0433463, -0.051398, -0.0314709, -0.000923992, +0.0226717, +0.0291947, +0.0190516, 
+0.000862548, -0.0143583, -0.0191781, -0.0129042, -0.000781586, +0.00974203, +0.0133, +0.00911591, 
+0.000685811, -0.00676893, -0.00938023, -0.00650807, -0.00058079, +0.00470399, +0.00658907, +0.00460843
};