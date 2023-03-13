import { Injectable } from '@angular/core';
import { Items } from './item';

@Injectable({
  providedIn: 'root'
})
export class ItemListService {

  constructor() { }

  items: Items[] = [
    { id: 1, name: 'Iphone', price: 1000, quantity: 10 },
    { id: 2, name: 'Samsung', price: 150, quantity: 8 },
    { id: 3, name: 'Xiaomi', price: 120, quantity: 15 },
  ];

  getItems(): Items[] {
    return this.items;
  }

  setItems(index: number): any {

    let item_quant: any = 0;
    item_quant = this.items[index].quantity;

    if (this.items[index].quantity > 0) {
      this.items[index].quantity = item_quant-1;
      return true;
    } else {
      return false;
    }



    // for (let i = 0; i < this.items.length; i++) {
    //   if (i == index) {
    //     if (this.items[i].quantity > 0) {
    //       this.items[i].quantity = this.items[i].quantity - 1;
    //     }
    //   }
    // }

  }
}
