class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t temp;
        uint32_t extract = 0;

        for(uint32_t i = 0; i < 32; i++){
            temp = ((1 << i) & n) >> i;

            extract |= temp << (31 - i);
        }

        return extract;
    }
};
