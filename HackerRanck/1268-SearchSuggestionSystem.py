from typing import List

products = ["mobile", "mouse", "moneypot", "monitor", "mousepad", "mousedoor", "mousemangu"]
searchWord = "mousep"

class Solution:
    def get_next_products(self, products, letters):
        letters_len = letters.__len__()
        l, r = 0, products.__len__() - 1

        while l <= r and (products[l].__len__() < letters_len or products[l][:letters_len] != letters):
            l += 1

        while l <= r and (products[r].__len__() < letters_len or products[r][:letters_len] != letters):
            r += 1

        next_products_aux = products[l:r+1]

        return next_products_aux, next_products_aux[:3]

    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        products.sort()  # n log(n)
        print(products)
        init = 0
        end = products.__len__()
        letters = ""
        next_products = products

        # n^2
        for letter in searchWord:
            letters += letter
            next_products, products_to_show = self.get_next_products(next_products, letters)
            print(letters, " ", products_to_show, " -> ", next_products)

        return next_products


print(Solution().suggestedProducts(products, searchWord))



