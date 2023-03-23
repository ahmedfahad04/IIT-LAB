import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';
import { ItemListService } from '../item-list.service';

@Component({
  selector: 'app-home',
  templateUrl: './home.component.html',
  styleUrls: ['./home.component.css']
})

export class HomeComponent implements OnInit{

  // Service -> TS(Component) -> View (while showing the items)
  // View -> TS(Component) -> Service (while requesting an item)

  // service should be placed in Constructor [Dependency Injection]
  constructor(private itemservice: ItemListService, private route: Router) { }
  
  fetched_items = this.itemservice.getItems();

  ngOnInit(): void {
    console.log(this.fetched_items);
  }

  requestItem(index: number): void {

    // alert(name + " requested");
    // let status = document.createElement("p");
    // status.innerHTML = this.fetched_items.at(index)?.name + " requested";
    // status.style.color = "green";
    // document.body.appendChild(status);
    // alert(index)

    // let item_quant: any = 0;
    // item_quant = this.fetched_items[index].quantity;
    // alert(item_quant)
    
    let status = this.itemservice.setItems(index);

    if (status == false) {
      alert(this.fetched_items[index].name + ' Finished! Try again Later!');
    }

  }

  updateItems(index: number): void {
    this.route.navigate(['update']);
    this.itemservice.setItemToBeSelected(index);
  }

  
  
}
